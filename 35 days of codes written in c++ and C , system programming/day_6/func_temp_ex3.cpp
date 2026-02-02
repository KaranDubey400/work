#include <iostream>
using namespace std;
template <class T1,class T2>
void show(T1 n,T2 v)
{
	for(T1 i=0;i<n;i++)
	{
		cout<<"\n"<<v<<"\n";
	}
}



int main()
{
	show(3.0,102);
	show(5,12.3);
	string  str="WIPRO";
	show('A',str);
}
