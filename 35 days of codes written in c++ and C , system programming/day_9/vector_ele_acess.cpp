#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <int> v={1,2,3,4,5};
	for(int i=0;i<9;i++)
	{
		cout<<v[i]<<"  ";
	}
	cout<<endl;
	for(int i=0;i<9;i++)
	{
		cout<<v.at(i)<<"  ";
	}
	cout<<endl;
}
