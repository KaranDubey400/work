#include<iostream>
#include <cstring>
using namespace std;

class test {
    private:
    int num; 
    char str[20]; 
    double var; 

    public:
    void display(){
        cout<<endl<<"num is "<<num<<"str is "<<str<<"var is"<<var<<endl;
    }

    test(){
        num = 0; 
        strcpy(str,"NONE");
        var = 1.0; 
    }
    test(const char*p , double d1){
        num =12;
        strcpy(str,p); 
        var = d1; 
    }
};

int main(){
    test t1; 
    t1.display(); 
    test t2("WIPRO",2.5);
    t2.display();
    return 0; 
   
}