#include <iostream>
using namespace std;

long int sum(long int n)
{
    long int s = 0;
    for(long int i = 0; i < n; i++) 
    {
        s += i;
    }
    return s;
}

int main()
{
    cout << sum(1000000000) << endl;
    return 0;
}