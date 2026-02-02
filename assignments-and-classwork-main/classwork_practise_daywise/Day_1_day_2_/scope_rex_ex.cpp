#include<iostream>
using namespace std;
extern int num1; // extern decalration  , a promise to compiler 
//that vriable is present somewhere in the program
int num1 =20;
int main(){
    int num1= 10;
    cout<<endl<<num1<<' '<<num1<<endl;
    //scope resolution to tell the compiler 
    // the variable is local or global ..
   //if we have same name of the varaible in both 
   //local and global use the scope resolution operator before
   // the variable name

}
int num1 =20;
//if we dont full fill the promise we get linker error