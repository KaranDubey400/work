#include <iostream>
#include <thread>
using namespace std;

void test()
{
	for(int i=0;i<10;i++)
	{
		cout<<"In test()  ";
	}
	cout<<endl;
}

int main()
{
	thread t1(test);
	t1.join();
	for(int a=0;a<10;a++)
	{
		cout<<"In main   ";
	}
	cout<<endl;
}
