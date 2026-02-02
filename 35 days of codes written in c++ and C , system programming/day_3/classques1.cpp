#include <iostream>
using namespace std;
//this and freind class 
class person {
    private:
    string name; 
    double height;
    public:
    void input(){
        cout<<"enter name and height"<<endl;
        cin>>name>>height;
    }
    void display(){
        cout<<name<<" "<<height<<endl;
    }

   

    person compare(person& pp){
        if(height>pp.height){
            return *this; // refers to object that called the compare function
        }
        else{
            return pp;
        }
    }

};



int main(){
    person p1,p2;
    p1.input();
    p2.input();
    p1.display();
    p2.display();

    person p3;
    p3= p1.compare(p2);//p1 calls compare function & passes p2 as argument //return value will be person type object
    
    p3.display();

   return 0; 
}