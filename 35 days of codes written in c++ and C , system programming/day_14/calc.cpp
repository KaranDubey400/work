#include <iostream>
#include "calc_header.hpp"

using namespace std;


int add(int n1, int n2) {
    int result = n1 + n2;
    cout << "\nResult of addition: " << result << endl;
    return result; 
}

int sub(int n1, int n2) {
    int result = n1 - n2;
    cout << "\nResult of subtraction: " << result << endl;
    return result;
}

int mul(int n1, int n2) {
    int result = n1 * n2;
    cout << "\nResult of multiplication: " << result << endl;
    return result;
}

int div_func(int n1, int n2) {
    if (n2 == 0) {
        cout << "\nError: Division by zero!" << endl;
        return 0;
    }
    int result = n1 / n2;
    cout << "\nResult of division: " << result << endl;
    return result;
}