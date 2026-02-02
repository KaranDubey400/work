#include <iostream>
#include <tuple>
#include <vector>
using namespace std; 
tuple<int,double> calc(int x,double y)
{
    int r = static_cast<double> (x/y);
    double d= (x%(int)y);
    return make_tuple(r,d);
}
int main()
{
    int a;
    double b; 
    tie(a,b) = calc(10,3);
    cout<<"\n Result is-"<<a<<" ";
    cout<<"\n Remainder is "<<b<<endl;

}