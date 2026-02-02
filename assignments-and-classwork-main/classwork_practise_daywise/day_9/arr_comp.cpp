#include <iostream>
#include <array>
using namespace std;

int main()
{
	array <int,3> a1={10,20,30};
	array <int,3> a2={10,20,50};
	if(a1==a2)
		cout<<"\nBoth arrrays are identical\n";
	else
		cout<<"\nBoth arrrays are not identical\n";
}
