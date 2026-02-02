#include <iostream>
using namespace std;
void show(int&&  n)
{
	cout<<endl<<n<<endl;
}

int main()
{
	const int x=100;
	show(x);
}
