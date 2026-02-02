#include <iostream>
using namespace std;
int main(){
    int arr[5] = {12,23,34,45,50};

    int * ptr;
    ptr= arr;
     cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<*ptr++<<endl;  // asktreik have 
    //higher priority than ++ . so will give 12 
    cout<<(*ptr)++<<endl;
    cout<<endl<<arr[1]<<endl;
ptr= arr; 
cout<<ptr<<endl;
    cout<<(*(ptr+2)++)<<endl;
}  
    
