#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void bg_task()
{
	this_thread::sleep_for(chrono::seconds(2));
	cout<<"\nTask is completed now...\n";
}
int main()
{
	thread t1(bg_task);
	t1.detach();
	cout<<"\nI am main ending now...\n";
	this_thread::sleep_for(chrono::seconds(5));
	cout<<"\nI am main ending now1...\n";
	return 0;
}

