#include <iostream>
#include <thread>
using namespace std;
int main()
{
	thread t1([]()
	{
		cout<<"\nHello i am a lambda function\n";
	});
	t1.join();
}
