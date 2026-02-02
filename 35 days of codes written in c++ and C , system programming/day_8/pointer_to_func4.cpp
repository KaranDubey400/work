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
	void (*p[4])(int,int)={&add,&sub,&mul,&div1};
	int num1,num2,choice=0;
	cout<<"Enter two numbers-";
	cin>>num1>>num2;
	while(choice!=5)
	{
		cout<<"1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit";
		cout<<"\nEnter your choice-";
		cin>>choice;
		if(choice<1 || choice>5)
		{
			cout<<"\nInvalid choice\n";
			continue;
		}
		else if(choice==5)
			break;
		else
			(*p[choice-1])(num1,num2);
	}
}
