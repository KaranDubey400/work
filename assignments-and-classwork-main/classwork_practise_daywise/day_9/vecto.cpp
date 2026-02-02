#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	v.reserve(100); //reserves memory for 100 elements, elemenates the need for
			//physical doubling of memory every time size goes beyond capacity
	cout<<"\nCapacity-"<<v.capacity()<<"  Size is-"<<v.size()<<endl;
	for(int i=0;i<100;i++)
	{
		v.push_back(i);
	}
	cout<<"\nCapacity-"<<v.capacity()<<"  Size is-"<<v.size()<<endl;
	v.push_back(900);
	cout<<"\nCapacity-"<<v.capacity()<<"  Size is-"<<v.size()<<endl;
};

