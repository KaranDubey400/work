#include <iostream>
#include <thread>
using namespace std;

void incr(int& a)
{
	a++;
	cout<<"\nValue after incr in incr()-"<<a<<endl;
}

int main()
{
	int a=10;
	cout<<"\nValue in main before incr-"<<a<<endl;
	thread t1(incr,ref(a));
	thread t2(incr,ref(a));
	thread t3(incr,ref(a));
	t1.join();
	t2.join();
	t3.join();

	cout<<"\nValue in main after incr-"<<a<<endl;
}

	

