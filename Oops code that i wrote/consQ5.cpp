#include <iostream>
#include <cstring>
using namespace std;

class printname {
       public:
    
    printname(int n) {
        cout << "integer" << n << endl;
    }

   
    printname(float n) {
        cout << "float: " << n << endl;
    }

    
    printname(double n) {
        cout << "doubke" << n << endl;
    }

    
    printname(char n) {
        cout << "character " << n << endl;
    }
};

int main() {
    printname s1(10);      
    printname s2(3.14f);   
    printname s3(99.99);   
    printname  s4('A');     

    return 0;
}
