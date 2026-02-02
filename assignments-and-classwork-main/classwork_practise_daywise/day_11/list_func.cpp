#include <iostream>
#include "list_header.hpp"
using namespace std;
extern student *start,*newnode,*prev1,*ptr;
int add()
{
	newnode = new student;
	cout<<"Enter rollno and cgpa-";
	cin>>newnode->rno>>newnode->cgpa;
	if(!start)
	{
		start=newnode;
		newnode->next=nullptr;
	}
	else if(newnode->rno<start->rno)
	{
		newnode->next=start;
		start=newnode;
	}
	else
	{
		for(ptr=start;(ptr) && ptr->rno<newnode->rno;prev1=ptr,ptr=ptr->next);
		if( (ptr) && ptr->rno==newnode->rno)
		{
			cout<<endl<<newnode->rno<<"  is duplicate...\n";
			return 1;
		}
		else
		{
			prev1->next=newnode;
			newnode->next=ptr;
		}
	}
	return 0;
}

int del()
{
	int mrno;
	if(!start)
	{
		cout<<"\nEmpty List...\n";
		return 1;
	}
	cout<<"Enter rollno to delete node-";
	cin>>mrno;
	if(mrno==start->rno)
	{
		ptr=start;
		start=start->next;
		delete ptr;
		ptr=nullptr;
	}
	else
	{

		for(ptr=start;(ptr) && ptr->rno!=mrno;prev1=ptr,ptr=ptr->next);
		if(ptr==nullptr)
		{
			cout<<endl<<mrno<<"  not found\n";
			return 1;
		}
		prev1->next=ptr->next;
		delete ptr;
		ptr=nullptr;
	}

	return 0;
}

int rview(student *p)
{
	if(!start)
	{
		cout<<"\nEmpty List...\n";
		return 1;
	}
	if(p!=nullptr)
	{
		rview(p->next);
		cout<<"\nRollno-"<<p->rno<<"  Cgpa-"<<p->cgpa;
	}

	return 0;
}

int view()
{
	if(!start)
	{
		cout<<"\nEmpty List...\n";
		return 1;
	}
	for(ptr=start;ptr!=nullptr;ptr=ptr->next)
	{
		cout<<"\nRollno-"<<ptr->rno<<"  Cgpa-"<<ptr->cgpa<<endl;
	}
	return 0;
}







