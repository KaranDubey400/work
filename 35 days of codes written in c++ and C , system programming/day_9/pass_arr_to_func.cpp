#include <iostream>
#include <array>
using namespace std;
void show(array<int, 5> a)
{
	for(int x:a)
	{
		cout<<x<<"   ";
	}
	cout<<endl;
}

int main()
{
	array<int,5> arr={12,6,32,4,7};
	show(arr);
}
