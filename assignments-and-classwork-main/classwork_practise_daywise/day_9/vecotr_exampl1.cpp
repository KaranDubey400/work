#include<iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1={10,20,30,40,50,60,70};
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1.at(i)<<" ";
	}
	cout<<endl;
	v1.insert(v1.begin()+2,65);
	cout<<"\nVector after insertion\n";
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1.at(i)<<" ";
	}
	cout<<endl;
	v1.insert(v1.end()-2,88);
	cout<<"\nVector after insertion\n";
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1.at(i)<<" ";
	}
	cout<<endl;
	v1.erase(v1.begin()+4);
	cout<<"\nVector after erasing the 5th element\n";
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1.at(i)<<" ";
	}
	cout<<endl;
	v1.clear(); //remove all elements from vector
	if(v1.empty())
	{
		cout<<"\nVector has become empty\n";
	}
	cout<<"\nSize-"<<v1.size()<<"  Capacity-"<<v1.capacity()<<endl;
}
