#include <iostream>
using namespace std;

int main(int ac, char ** av){
    if(ac<3){
        cout<<"invalid number of arguments"<<endl;
        return 1;
    }
    for(int i =0 ; i< atoi(av[1]); i++){
        cout<<av[2]<<endl;
    }
    }
