//calloc and malloc
#include <iostream>
#include <cstdlib>
using namespace std;

class person {
    private :
    int id; 
    string name; 
    public:
    person (int i , string nm ){
        cout<<endl<<"memory allocated for string and int "<<endl;
        id =i;
        name =nm;
    }

    void show()
    {
        cout<<"Id is "<<id<<" Name is "<<name<<endl;
    
    }

    //overloading the new operator 
    void * operator new(size_t size)
    {
        cout<<endl <<"new operator being over loaded "<<endl;
        void *p = malloc(size);
        return p;
    }
      //p here is void type pointer 
    //deallocating operator 
    void operator delete(void *p)
      {
        cout<<endl<<"delete operator being over loaded "<<endl;
        free(p);
      }
};

int main(){
    person *p = new person (100 ,"sundar");
    p->show();
    // p here is person type pointer 
    delete p ; 
    p = nullptr;
    return 0;


}