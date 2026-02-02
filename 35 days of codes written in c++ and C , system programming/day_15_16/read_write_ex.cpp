#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <shared_mutex>
using namespace std;

vector <int> data1;
shared_mutex rw_lock;

void reader(int id)
{
	shared_lock<shared_mutex> lock(rw_lock);
	cout<<"\nI am the reader-"<<id<<" the read data size-"<<data1.size()<<endl;
}

void writer(int n)
{
	unique_lock<shared_mutex> lock(rw_lock);
	data1.push_back(n);
	cout<<"\nI am writer.. i hv added-"<<n<<endl;
}

int main()
{
	thread w1(writer,10);
	thread r1(reader,1);
	thread r2(reader,2);
	thread w2(writer,20);
	thread w3(writer,40);
	thread r3(reader,3);
	w1.join();
	r1.join();
	r2.join();
	w2.join();
	w3.join();
	r3.join();
}





