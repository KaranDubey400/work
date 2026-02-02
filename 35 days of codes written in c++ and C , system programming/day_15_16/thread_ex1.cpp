#include <iostream>
#include <thread>
using namespace std;
void show()
{
	cout<<"\nExploring the world of threads\n";
}

int main()
{
	thread t1(show); //creating a thread object and calling a function using param-const
	t1.join();//parent waits for the child thread to finish
	cout<<"\nMain finishes\n";
}
