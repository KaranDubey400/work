#include <iostream>
using namespace std;

template<class T>

void show(T var)
{
	cout<<"Value is-"<<var;
	cout<<endl<<"Type is-"<<typeid(var).name()<<endl;
}

int main()
{
	show(10.2);
	show(100);
	show(4.5f);
	string st="Hello";
	show(st);
}
