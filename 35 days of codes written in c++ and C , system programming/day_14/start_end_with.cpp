#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str = "We are learning C++";

    
    if (str.starts_with("We")) {
        cout << "\nIts true-";
    } else {
        cout << "\nIts false-";
    }


    if (str.ends_with("C++")) {
        cout << "\nIts true-";
    } else {
        cout << "\nIts false-";
    }

    cout << endl;
    return 0;
}