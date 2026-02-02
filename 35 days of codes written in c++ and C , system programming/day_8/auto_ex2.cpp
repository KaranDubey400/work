#include <iostream>
using namespace std;
int main()
{
	double arr[5];
	for(auto& k:arr)
	{
		cin>>k;
	}

	for(auto& p:arr)
	{
		cout<<p<<" ";
	}
	cout<<endl;
}
