#include <iostream>
using namespace std; 

namespace n1
{
    void show()
    {
        cout<<"i am show function "<<endl; 
    }
}

void show(){
    cout<<"i am independent show function n1 "<<endl;
}

namespace n2
{
    void show()
    {
        cout<<"i am show function in n2 "<<endl; 
    }
}

int main(){
    show();
    n1::show();
    n2::show();
    return 0;

}

