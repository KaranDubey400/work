#include <iostream>
using namespace std;

class base {
       private: 
       
public:
//declaration of pure virtual function 
    virtual void show() = 0;

};

class der : public base{
      public:
      void  show1()
      {
        cout<<endl<<" i am from derived "<<endl;
      }
};

int main (){
    base * ptr = new der;

      ptr->show1();
}