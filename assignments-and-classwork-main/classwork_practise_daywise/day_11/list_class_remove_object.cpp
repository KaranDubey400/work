#include <iostream>
#include <list>
using namespace std;
class student
{
	private:
		int roll;
		double cgpa;
	public:
	        student()=default;
		student(int& s, double c)
		{
			roll=s;
			cgpa=c;
		}
		void input()
		{
			cout<<"Enter rollno and cgpa-";
			cin>>roll>>cgpa;
		}

		void output()
		{
			cout<<"\nRoll-"<<roll<<"  Cgpa-"<<cgpa<<endl;
		}
		bool operator ==(const student& s) const
		{
			return roll==s.roll;
		}
};
int main()
{
	list <student> l1;
	student s1;
	int ch=1;
	while(ch==1)
	{
		s1.input();
		l1.push_back(s1);
		cout<<"\nEnter 1 to con...-";
		cin>>ch;
	}
	list<student>::iterator it;
	for(it=l1.begin();it!=l1.end();it++)
	{
		it->output();
	}
	cout<<endl;
	int mrno=0;
	cout<<"Enter rollno to remove-";
	cin>>mrno;
	student temp(mrno,0.0);
	l1.remove(temp);
	for(it=l1.begin();it!=l1.end();it++)
	{
		it->output();
	}
	cout<<endl;
}
