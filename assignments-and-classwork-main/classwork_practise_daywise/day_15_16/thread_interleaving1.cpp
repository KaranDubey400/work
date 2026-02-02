#include <iostream>
#include <thread>
using namespace std;
void show(const char *tname)
{
	for(int i=0;i<5;i++)
	{
		cout<<endl<<tname<<"  is on iteration-"<<i<<" on thread-"<<this_thread::get_id()<<endl;
	}

}

int main()
{
	thread t1(show,"Thread-1");
	thread t2(show,"Thread-2");
	t1.join();
	t2.join();
}

