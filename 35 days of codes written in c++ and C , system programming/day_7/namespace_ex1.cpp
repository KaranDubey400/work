#include <iostream>
using namespace std;

namespace n1  
{
    int num = 10 ;
}

namespace n2
{
    int num = 100 ; 
}

int main(){
    int num = 500; 
    cout<<num<<" "<<n1::num<<" "<<n2::num<<endl;
    return 0;

}