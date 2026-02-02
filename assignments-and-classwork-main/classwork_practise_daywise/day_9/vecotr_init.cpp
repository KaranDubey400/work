#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int>  v1(5); //5 elements all init to 0
	cout<<v1.size()<<"  "<<v1.capacity()<<endl;
	vector<int> v2(5,100);//5 elements, all initialized to 100
	vector<int> v3={1,2,3};//list of initializing values
	cout<<v3.size()<<"  "<<v3.capacity()<<endl;
}
