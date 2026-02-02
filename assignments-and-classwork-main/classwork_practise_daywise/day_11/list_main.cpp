#include <iostream>
#include "list_header.hpp"
using namespace std;
student *start,*newnode,*prev1,*ptr;
int main()
{
	start=nullptr;
	system("clear");
	int ch=0;
	while(ch!=5)
	{
		cout<<"\n1.Add Node\n2.Delete Node\n3.View List\n4.View list in reverse\n5.Exit\n";
		cout<<"Enter a choice-";
		cin>>ch;
		switch(ch)
		{
			case 1: add();
				break;
			case 2: del();
				break;
			case 3: view();
				break;
			case 4: rview(start);
				break;
			case 5: break;
			default: cout<<"\nInvalid choice..\n";
		}
	}
}

