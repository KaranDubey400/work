#include <iostream>
#include <tuple>
#include <vector>
using namespace std; 

int main()
{
    // display the tuple
    tuple <int,double,string> t1(100,7.8,"hello");
    cout<<get<0>(t1)<<" "<<get<1>(t1)<<" "<<get<2>(t1)
}