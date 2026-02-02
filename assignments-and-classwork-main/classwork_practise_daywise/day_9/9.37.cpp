#include <iostream>
#include <array>
using namespace std;

int main(){
    array<double,5> arr= {1,2,3,4,5,5,6,6,};

    for(int i =0; i < arr.size();i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}