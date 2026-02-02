#include <iostream>
using namespace std;
int main()
{
	int *p=new int(100);
	cout<<*p<<"  "<<p<<endl;
	delete p;
	p=nullptr;
	cout<<*p<<"  "<<p<<endl;

}
