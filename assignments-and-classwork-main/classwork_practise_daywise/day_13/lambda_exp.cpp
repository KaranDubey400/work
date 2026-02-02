#include <iostream>

using namespace std;

int main() {
 
    auto add = [](int a, int b) -> int 
    {
        return a + b;
    };

 
    int r = add(100, 200); // labda called

    cout << "\nResult is - " << r << endl;

    return 0;
}