#include <iostream>
using namespace std;

int main() {
    int num1 = 10, num2 = 20;

    
    auto show = [&]() {
        num1 += 20;  
        num2 += 50; 
        cout << endl << num1;
        cout << endl << num2 << endl;
    };

    show();

    return 0;
}