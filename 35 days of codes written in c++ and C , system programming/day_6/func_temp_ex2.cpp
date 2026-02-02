#include <iostream>
using namespace std;

template <typename T,typename U>
void show(T var1,U var2)
{
	cout<<var1<<" "<<var2<<endl;
}



int main()
{
	string str="WIPRO";
	show(10,str);
	show(2.3f,'A');
	show(12.5,22);
}
