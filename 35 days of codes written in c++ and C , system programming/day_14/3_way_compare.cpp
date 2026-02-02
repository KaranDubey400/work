#include <iostream>
#include <compare> 

using namespace std;

int main() {
    double v1 = 10.2, v2 = 8.3;
    
    
    auto result = v1 <=> v2;

    if (result < 0) {
        cout << endl << v1 << " is less than " << v2;
    } 
    else if (result > 0) {
        cout << endl << v1 << " is greater than " << v2;
    } 
    else {
        cout << "\nv1 and v2 are equal\n";
    }

    return 0;
}