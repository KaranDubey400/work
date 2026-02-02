#include <iostream>
#include <memory>
using namespace std;

void leak()
{
	int *karn=new int(50);
	(*karn)++;
	cout<<"the value is"<<*karn<<endl;
}
void no_leak()
{
	unique_ptr<int> karn(new int(50));
	(*karn)++;
	cout<<endl<<"value is"<<*karn<<endl;
}

int main()
{
   leak();
	//no_leak();
}
