#include <iostream>
#include <thread>
#include <mutex>
#include<condition_variable>
#include <map>
#include<vector>
#include<fstream>
using namespace std;

struct Node{
  int deviceId;
  int time;
  double value;
  Node * next;
};
  
Node* list1 = nullptr;
Node* list2=nullptr;

mutex mtx;
condition_variable cv1,cv2,cv3;
bool genDone = false, procDone= false, writeDone=false;

//creating Thread 1
void generateData()
{

  for(int i =0;i<10;i++)
  {
    Node* n= new Node{i%3,i,i*10.0,list1};
    list1 = n;
    }
    lock_guard<mutex>lock(mtx);
    genDone=true;
    cv1.notify_one();
}

//creating Thread 2

void processData()
{
    unique_lock<mutex> lock(mtx);
      cv1.wait(lock,[]{return genDone;});
      
      for (Node* p=list1;p;p=p->next)
      {
      Node* n= new Node{p->deviceId,p->time,p->value *500.0,list2};
      list2=n;
      }
      procDone=true;
      cv2.notify_one();
}

//creating Thread 3

void writeToFile()
{
  unique_lock<mutex>lock(mtx);
    cv2.wait(lock,[]{return procDone;});
    ofstream out("data.txt");
    for (Node* p= list2;p;p=p->next)
    {
      out<<p->deviceId<<"  " <<p->value<<"\n";
      }
      out.close();
      writeDone=true;
      cv3.notify_one();
}
 
//creating Thread 4 for avg calc..

void average() 
{
  unique_lock<mutex>lock(mtx);
  cv3.wait(lock,[]{ return writeDone;});
  
  ifstream in("data.txt");
  map<int,vector<double>>data;
  
  int id;
  double val;
  while (in >> id >> val)
    data[id].push_back(val);
    
    for (auto& d: data){
      double sum = 0;
      for (double v:d.second) sum+= v;
      cout<<"Device"<<d.first<<"avg is: "<<sum/d.second.size()<<"\n";
      }
}

int main()
{
  thread t1(generateData);
  thread t2(processData);
  thread t3(writeToFile);
  thread t4(average);
  
  t1.join();t2.join();t3.join();t4.join();
  return 0;

}
      
      
      
        

