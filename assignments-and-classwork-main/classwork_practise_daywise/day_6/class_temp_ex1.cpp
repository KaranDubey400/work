#include <iostream>
using namespace std;

template <typename T1,typename T2>
class test
{
	private:
	T1 var1;
	T2 var2;
	public:
	test(T1 v1,T2 v2)
	{
		var1=v1;
		var2=v2;
	}
	void display()
	{
		cout<<endl<<var1<<"----"<<var2<<endl;
	}
};
int main()
{
	test obj1(10.2,'A');
	obj1.display();
	test obj2(100,7.5f);
	obj2.display();
}
