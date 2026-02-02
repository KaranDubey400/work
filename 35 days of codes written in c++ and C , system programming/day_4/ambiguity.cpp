//ambiguity due to implicit type conversion all three ambiguities
#include <iostream>
using namespace std;

void test (int x){
    cout<<endl<<"converted to int"<<endl;
}

void test (float x){
    cout<<endl<<"converted to float"<<endl;

}

int main (){
    test()
}