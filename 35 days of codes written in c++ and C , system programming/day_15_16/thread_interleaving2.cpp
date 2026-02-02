#include <iostream>
#include <thread>
using namespace std;
int balance=1000;
void withdraw(int amt)
{
	if(balance>=amt)
	{
		balance-=amt;
	}
}

int main()
{
	thread t1(withdraw,700);
	thread t2(withdraw,700);
	t1.join();
	t2.join();
	cout<<" balance-"<<balance<<" ";
}
