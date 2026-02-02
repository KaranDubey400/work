#include <iostream>
#include <thread>
using namespace std;
void sum(int a, int b)
{
	cout<<"\nResult of addition-"<<a+b<<endl;
}

int main()
{
	thread t1(sum,10,20); //passing arguements to thread
	t1.join ();
}


