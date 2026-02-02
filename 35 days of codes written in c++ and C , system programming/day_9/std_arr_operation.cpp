#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
int main()
{
	array<int,6> arr={12,7,23,6,45,8};
	sort(arr.begin(),arr.end());
	//check if the array is sorted or not
	if(is_sorted(arr.begin(),arr.end()))
	{
		cout<<"\nArray is sorted\n";
	}
	else
	{
		cout<<"\nArray is not sorted\n";
	}
//	arr.at(1)=3;
	cout<<"\nNo. of times 3 is present-"<<count(arr.begin(),arr.end(),3)<<endl;

}


