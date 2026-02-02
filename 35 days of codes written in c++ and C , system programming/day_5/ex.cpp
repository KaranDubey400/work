#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str = "Hello";
    

    int badIndex = 100; 

    cout << "--- METHOD 1: Using .at() (Safe) ---" << endl;
    try {
       
        cout << str.at(badIndex) << endl; 
    }
    catch (const out_of_range& e) {
        cout << "erorr " << e.what() << endl;
        cout << "The program did NOT crash! We handled the error." << endl;
    }

    cout << " method " << endl;
    cout << "Warning: This might print garbage or crash silently." << endl;
    
    cout << "Result: " << str[badIndex] << endl; 

    return 0;
}