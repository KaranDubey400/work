#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1={1,2,3,4,5};
	cout<<"\nSize of vector1 is -"<<v1.size()<<endl;
	vector<int> v2=move(v1); //Deep-copy of v1 into v2
	cout<<"\nAfter copying\n";
	cout<<"\nSize of vector1 is -"<<v1.size()<<endl;
	cout<<"\nSize of vector2 is -"<<v2.size()<<endl;
}

