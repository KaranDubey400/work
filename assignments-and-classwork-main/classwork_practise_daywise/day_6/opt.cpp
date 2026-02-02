#include <iostream>
using namespace std;

template <class T1,class T2>
class test
{
	private:
	T1 var1;
	T2 var2;
	public:
	test(T1 a,T2 b)
	{
		var1=a;
		var2=b;
	}
	void operator +()
	{
		cout<<endl<<"Added-"<<var1+var2;
	}
	void operator -()
	{
		cout<<endl<<"subtracted-"<<var1-var2;
	}
	void operator *()
	{
		cout<<endl<<"Multiplied-"<<var1*var2;
	}
	void operator / (double)
	{
		cout<<endl<<"Divided-"<<var1/var2;
	}
};
int main()
{
	test t1(10,2.5);
	char sym;
	cout<<"Enter the symbol for add,sub,mul or div-";
	cin>>sym;
	if(sym=='+')
	{
		+t1;
	}
	else if(sym=='-')
	{
		-t1;
	}
	else if(sym=='*')
	{
		*t1;
	}
	else if(sym=='/')
	{
		t1/1;
	}
	else
		cout<<"Invalid operation-"<<endl;
}
