#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> l1;
	l1.push_back(10);

	l1.push_back(8);

	l1.push_back(8);

	l1.push_back(20);


	l1.push_back(20);

	l1.push_front(77);

	l1.push_front(40);

	l1.push_front(40);

	cout<<"\ndisplaying list\n";
	for(int i:l1)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	l1.sort();
	cout<<"\ndisplaying list after sorting\n";
	for(int i:l1)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	l1.unique();
	cout<<"\ndisplaying list after removing duplicates\n";
	for(int i:l1)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

