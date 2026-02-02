#include <iostream>
using namespace std;

void show(){
    cout<<endl<<"i am show with 0 arg"<<endl;
    
}

void show(int n1,int n2){
    cout<<endl<<"i am show with 2 arg"<<endl;
 
}

void show(int n1,int n2, int n3){
    cout<<endl<<"i am show with 3 arg"<<endl;
}

int main(){

    show();
    show(10,20);
    show(10,20,30);
    return 0;

}