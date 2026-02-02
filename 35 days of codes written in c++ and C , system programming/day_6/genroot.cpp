#include <iostream>
using namespace std;
int main()
{
	int num,gr=0;
	cout<<"Enter number to find gen root-";
	cin>>num;
	if(num<10)
		gr=num;
	else
		gr=(num%9==0)?9:num%9;

	cout<<endl<<"Generic root is-"<<gr<<endl;
}
