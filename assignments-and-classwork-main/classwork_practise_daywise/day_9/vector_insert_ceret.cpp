#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1;
	cout<<"\nSize is-"<<v1.size()<<endl;
	cout<<"\nCapacity is-"<<v1.capacity()<<endl;
	v1.push_back(10);
	cout<<"\nSize is-"<<v1.size()<<endl;
	cout<<"\nCapacity is-"<<v1.capacity()<<endl;
	v1.push_back(20);
	cout<<"\nSize is-"<<v1.size()<<endl;
	cout<<"\nCapacity is-"<<v1.capacity()<<endl;
	v1.push_back(30);
	cout<<"\nSize is-"<<v1.size()<<endl;
	cout<<"\nCapacity is-"<<v1.capacity()<<endl;
	v1.push_back(50);
	v1.push_back(60);
	cout<<"\nSize is-"<<v1.size()<<endl;
	cout<<"\nCapacity is-"<<v1.capacity()<<endl;
	for(int i:v1)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}
