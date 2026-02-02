#include <iostream>
using namespace std;
void add(int n1, int n2)
{
	cout<<"\nResult of addition is-"<<n1+n2<<endl;
}
void sub(int n1, int n2)
{
	cout<<"\nResult of subtraction is-"<<n1-n2<<endl;
}
void mul(int n1, int n2)
{
	cout<<"\nResult of multiplication is-"<<n1*n2<<endl;
}
void div1(int n1, int n2)
{
	cout<<"\nResult of division is-"<<n1/n2<<endl;
}
int main()
{
	system("clear");
	int num1,num2,choice=0;
	cout<<"Enter two numbers-";
	cin>>num1>>num2;
	while(choice!=5)
	{
		cout<<"1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit";
		cout<<"\nEnter your choice-";
		cin>>choice;
		switch(choice)
		{
			case 1: add(num1,num2);
				break;
			case 2: sub(num1,num2);
				break;
			case 3: mul(num1,num2);
				break;
			case 4: div1(num1,num2);
				break;
			case 5: break;
			default: cout<<"\nInvalid choice\n";
		}
	}
}
