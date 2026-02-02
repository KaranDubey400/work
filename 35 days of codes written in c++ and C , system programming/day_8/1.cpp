//function array , pointer to function . remember function syntax
#include <iostream>
using namespace std;

void add(int a, int b) {
     cout << endl<< "addition = " << a + b; 
    }

void sub(int a, int b) { 
    cout << endl<<"subtraction = " << a - b;

}

void mul(int a, int b) { 
    cout <<endl<<"multiply = " << a * b;

}


void div1(int a, int b) {
    if (b == 0){
        cout << endl<<"err not possible";
    }
    else{
    cout << endl<<"division = " << a / b;
    }

}

int main()
{
    int n1, n2, ch;

    
    void (*funcp[4])(int, int) = { add, sub, mul, div1 };

    cout << "enter numbers ";
    cin >> n1 >> n2;

    cout << "\n1. Add\n2. Sub\n3. Mul\n4. Div";
    cout << endl<<"enter choice: ";
    cin >> ch;

    if (ch >= 1 && ch <= 4)
        funcp[ch - 1](n1, n2);   
    else
        cout << endl<<"invalid choice ";

    return 0;
}
