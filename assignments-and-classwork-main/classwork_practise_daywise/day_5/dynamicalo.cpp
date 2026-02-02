#include <iostream>
#include <string>
using namespace std;

class test {
    int num;
    string str;

public:
    test() {
        int num =0 ; 
        str = " ";
    }
    void input()
    {
        cout<<"Enter a number and a string-";
        cin>>num>>str;
    }
    void output()
    {
        cout<<endl<<"Number is-"<<num<<" String is-"<<str<<endl;
    }
};

int main()
{
   
    test *ptr=new test[3];  //dynamically
    for(int i=0;i<3;i++)
    {
        ptr[i].input();
        
    }
    for(int i=0;i<3;i++)
    {
        
        ptr[i].output();
    }
    delete [] ptr;
      delete ptr; 
    ptr=nullptr;
    return 0;

    
    // ptr->input(); //statically
    // ptr->output();
    // delete ptr; 
    // ptr=nullptr; //Dangling pointer situation without this line
}