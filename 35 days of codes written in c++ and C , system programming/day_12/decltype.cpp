#include <iostream>
using namespace std;

// Generic function to find minimum of two values
//generic function which  finds minimum of 2 vars and return type is auto,atically type 
//of the variable which is returned  
template <class A, class B>
auto findmin(A v1, B v2) -> decltype(v1 < v2 ? v1 : v2)
{
    return (v1 < v2) ? v1 : v2;
}

int main()
{
    cout << endl << findmin(4, 3.67) << endl;
    cout << endl << findmin(4.2f, 5) << endl;

    return 0;
}
