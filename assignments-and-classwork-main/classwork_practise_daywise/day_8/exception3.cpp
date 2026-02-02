#include <iostream>
using namespace std; 


int main(){


try {
    throw 10;
}
catch (char c) {
    cout << "Char error";
}
catch (int i) {
    cout << "Int error";
}
catch (...) {
    cout << "Unknown error";
}


}