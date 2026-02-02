#include <iostream>
using namespace std;

class parent {
    private :
    int num ; 
    public :
    parent(){
        num =0; 
        cout<<endl<<"parent  default constructor"<<endl;
    
    }

    void show(){
        cout<<endl<<"i am show in parent "<<endl;
    }
};

class child1 : public parent {
    public:
    child1(){
        cout<<endl<<"child1 default constructor"<<endl;
    }
    
    };

 class child2 : public parent {
    public:
    child2(){
        cout<<endl<<"child2 default constructor"<<endl;
    }
   
    };

class schild: public child1 , public child2{
    public:
    schild(){
        cout<<endl<<"schild default constructor"<<endl;
    }
  
};

int main(){
    schild ss;
    
}