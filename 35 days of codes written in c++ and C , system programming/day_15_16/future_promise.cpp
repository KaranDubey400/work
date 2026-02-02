#include <iostream>
#include <future>
#include <thread>
using namespace std;

//worker thread

void calc(promise<int> p)
{
	int sum=0;
	for(int i=1;i<=10;i++)
	{
		sum+=i;
	}
	p.set_value(sum);
}

int main()
{
	promise <int> pp;
	future<int> ff=pp.get_future();
	thread t1(calc,move(pp)); //moves the future value to the thread function
	cout<<"\nWaiting for the return value...\n";
	int result=ff.get();
	cout<<"Result is-"<<result<<endl;
	t1.join();
}

