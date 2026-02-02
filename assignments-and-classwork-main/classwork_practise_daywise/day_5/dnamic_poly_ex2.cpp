#include <iostream>
using namespace std;

class base {
    public:
 virtual    void show(){
        cout<<endl <<"i am show form base"<<endl;
    }
};

class derived : public base {
    public :
    void show(){
        cout<<endl<<"i am show form derived"<<endl;
    }
};

int main(){
    base * ptr;
    derived dd;
    ptr = &dd;
    ptr->show();
    dd.show();
    // dd.base::show();
}