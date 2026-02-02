#include <iostream>
#include <thread>
using namespace std;
void task(int id)
{
	cout<<" Thread id-"<<id<< " ";
}
int main()
{
	thread t1(task,1);
	thread t2(task,2);
	thread t3(task,3);
	thread t4(task,4);
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	cout<<endl;
}
