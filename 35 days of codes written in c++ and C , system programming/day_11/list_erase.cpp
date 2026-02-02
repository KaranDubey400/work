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
	cout<<"\nDisplaying list\n";
	list<int> :: iterator it; //declaring an iterator for list of integers
	for(it=l1.begin();it!=l1.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	l1.sort();
	it=l1.begin();
	it++;
	it++;
	l1.insert(it,30); //inserting element at position where iterator is
	
	cout<<"\nDisplaying listafter insert operation\n";
	for(it=l1.begin();it!=l1.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	it=l1.end();
	it--;
	it--;
	l1.erase(it);
	cout<<"\nDisplaying list after erase operation\n";
	for(it=l1.begin();it!=l1.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	int r;
	cout<<"Enter value to remove from list-";
	cin>>r;
	int flag=0;
	for(auto i:l1)
	{
		if(i==r)
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		cout<<"\n Value-"<<r<<" not found\n";
	}
	else
		l1.remove(r);
	cout<<"\nDisplaying list after remove operation\n";
	for(it=l1.begin();it!=l1.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

