#include <iostream>
using namespace std;

template <class T>
void show(T var)
{
	cout<<var<<endl;
}



int main()
{
	show(10);
	show('A');
	show(12.5);
}
