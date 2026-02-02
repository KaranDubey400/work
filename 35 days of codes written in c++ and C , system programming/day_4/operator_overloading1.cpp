// + operator ooverloading 
#include <iostream>
using namespace std; 

class number {
  private:
  int first_num; 
  int second_num; 
  public:
  
  number(){
    first_num = second_num =0; 
  }
  number(int fn , int sn ){
    first_num = fn; 
    second_num = sn; 
  
  }

  void disply(){
    cout<<endl<<"first number is "<< first_num<<endl; 
    cout<<endl<<"second number is "<< second_num<<endl; 
    
  }
  number operator + (number&  nn){
    number temp;
    temp.first_num = first_num + nn.first_num; 
    temp.second_num = second_num + nn.second_num; 
    return temp; 
  }

  number operator - (number&  nn){
    number temp;
    temp.first_num = first_num - nn.first_num; 
    temp.second_num = second_num - nn.second_num; 
    return temp; 
  }
};

int main (){
    number n1(10,20), n2(50,60), n3(5,7),n4,n5; 
    n1.disply(); 
    n2.disply(); 

    n3.disply();
    n4 = n1+n2+n3;   //overloading  n3 = n1. +(n2)
    n4.disply();
    n5 =n4-n1;
    n5.disply();
    return 0; 


}   