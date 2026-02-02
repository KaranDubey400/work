#include<iostream>
#include<thread>
#include<mutex>
#include<map>
#include<queue>
#include<vector>
#include<condition_variable>
#include<chrono>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;

map<int,string> interrupt_map;
queue<pair<int, string>> interrupt_queue;
mutex mt;
condition_variable cv;
bool stop=false;
int cnt=0;
int sz=0;

void load_interrupts(const string& file_name)
{
  ifstream file(file_name);
  int ID;
  string Btn;
  
  if(!file)
  {
    cout<<"\n Unable to open file\n";
    return ;
  }
  
  while(file>>ID>>Btn)
  {
    interrupt_map[ID]=Btn;
  }
  
  file.close();
}

void Random_gen()
{
  while(!stop)
  {
    int interrupt_ID = (rand()%sz)+1;
    
    {unique_lock<mutex> lock(mt);
    interrupt_queue.push({interrupt_ID,interrupt_map[interrupt_ID]});
    }
    cv.notify_one();
    
    this_thread::sleep_for(chrono::seconds(1));
  }
}

void writer()
{
  ofstream fout("interrupt_log.txt", ios::app);
  
  while(!stop)
  {
    
    unique_lock<mutex> lock(mt);
    cv.wait(lock,[]{return !interrupt_queue.empty() || stop;});
    
    
    if(!interrupt_queue.empty())
    {
      int interrupt_ID = interrupt_queue.front().first;
      string interrupt_Btn = interrupt_queue.front().second;
      interrupt_queue.pop();
      fout<<interrupt_ID<<" "<<interrupt_Btn<<endl;
    }
     
  }
  fout<<"Threads: "<<cnt<<endl;
  fout.close();
}

int main()
{
  load_interrupts("interrupt_file.txt");
  sz=interrupt_map.size();
  if(interrupt_map.empty())
  {
    cout<<"File is empty"<<endl;
    return 1;
  }
  vector<thread> arr(sz);
  
  for(int i=0; i<sz; i++)
  {
    arr[i]=thread(Random_gen);
    cnt++;
  }
  
  thread W(writer);
  cin.get();
  stop = true;
  cv.notify_all();
  
  for(int i=0; i<sz; i++)
  {
    arr[i].join();
    //cnt--;
  }
  W.join();
  
  return 0;
}
