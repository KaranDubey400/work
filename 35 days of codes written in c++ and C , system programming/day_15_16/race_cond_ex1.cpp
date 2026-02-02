#include <iostream>
#include <thread>
using namespace std;
int ctr=0;
void incr()
{
	for(int i=0;i<100000;i++)
	{
		ctr++;
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
