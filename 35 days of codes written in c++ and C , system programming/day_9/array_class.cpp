#include <iostream>
#include <array>
using namespace std;

class student
{
	public:
		int rno;
		student(int r=0) : rno(r) {}
};

int main()
{
	array<student,3> arr={student(100),student(101),student(102)};
	for(auto a:arr)
	{
		cout<<a.rno<<" ";
	}
	cout<<endl;
	//using a c-style pointer on a std::array
	student *p=arr.data(); //data function returns a c stryle pointer
	cout<<(p+3)->rno<<endl;

}
