#include <iostream>
using namespace std;
void big(int n)
{
	cout<<endl<<n<<" is a big number\n";
}
void small(int n)
{
	cout<<endl<<n<<" is a small  number\n";
}
void test(void(*p)(int), int nn)
{
	(*p)(nn); //calling either big() or small() depending on the address received
}
int main()
{
	int num;
	cout<<"Enter a number-";
	cin>>num;
	(num>1000)?test(&big,num):test(&small,num);//adress of big or small passed to test
	return 0;
}
