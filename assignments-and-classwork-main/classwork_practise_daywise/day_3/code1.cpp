#include<iostream>
using namespace std;
//call by value 
// void test(int,int); //prototype

// int main(){
//     int n1=10, n2=20;

//     cout<<n1<<" "<<n2<<endl;
//     test(n1,n2); //call by value"

//     cout<<endl<<"after function call"<<endl;
//     cout<<n1<<" "<<n2<<endl;
//     return 0;

// }

// void test(int n1,int n2){
//     n1+=5;
//     n2+=5;
//     cout<<n1<<" "<<n2<<endl;

// }


// //pass by address
// void test(int*,int*); //prototype

// int main(){
//     int n1=10, n2=20;

//     cout<<n1<<" "<<n2<<endl;
//     test(&n1,&n2); //call by value"

//     cout<<endl<<"after function call"<<endl;
//     cout<<n1<<" "<<n2<<endl;
//     return 0;

// }

// void test(int *n1,int *n2){
//     *n1+=5;
//     *n2+=5;
//     cout<<*n1<<" "<<*n2<<endl;

// }


// call by reference 

void test(int&,int&); //prototype

int main(){
    int n1=10, n2=20;

    cout<<n1<<" "<<n2<<endl;
    test(n1,n2); //call by reference"

    cout<<endl<<"after function call"<<endl;
    cout<<n1<<" "<<n2<<endl;
    return 0;

}

void test(int &p1,int &p2){  // recive as reference 
    p1+=5;
    p2+=5;
    cout<<p1<<" "<<p2<<endl;

}

