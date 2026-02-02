#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int ctr=0;
mutex mt; //declaring a mutex variable to be used for locking
void incr()
{
	for(int i=0;i<100000;i++)
	{
		mt.lock(); //locking critical section. for one thread at a atime
		ctr++;
		mt.unlock();
	}
}

int main()
{
	thread t1(incr);
	thread t2(incr);
	t1.join();
	t2.join();
	cout<<endl<<"ctr val-"<<ctr<<endl;
}




parallelism - 
