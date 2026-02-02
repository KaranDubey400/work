#include <iostream>
using namespace std;
int main()
{
	double arr[5];
	for(auto<double> ptr:arr)
	{
		cin>>ptr;
	}

	for(auto <double> ka:arr)
	{
		cout<<ka<<endl;
	}
	cout<<endl;
}
