#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(8);
   

	l1.push_back(20);
	l1.push_front(77);
	l1.push_front(40);

	cout<<"\ndisplaying list\n";
	list<int> :: iterator it;
	for(it=l1.begin();it!=l1.end();++it)

	{
		cout<<*it<<" ";
	}
	cout<<endl;
	l1.sort();
	cout<<"\n  displaying list after sorting\n";
	for(it=l1.begin();it!=l1.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	l1.reverse();

	
	cout<<"\n displaying list after reversing\n";
	
	for(it=l1.begin();it!=l1.end();++it)

	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

