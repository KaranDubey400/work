#include <iostream>
#include <cstring>
using namespace std;

class Rectangle{
     int length ,breadth ; 

     public:
     Rectangle(){
        this->length = 0 ; 
        this->breadth= 0 ; 
     }

     Rectangle(int one){
         this->length = one ; 
         this->breadth= one ; 

     }
      
     Rectangle(int l,int b){
        this->length = l ; 
        this->breadth= b ; 
     }

      void display()
      {
        cout<<"area of rect is " <<length*breadth<<endl;

        
      }



};

int main(){
    Rectangle s1;
    s1.display();

    Rectangle s2(10);
    s2.display();

    Rectangle s3(10,20);
    s3.display();

    return 0 ;
}