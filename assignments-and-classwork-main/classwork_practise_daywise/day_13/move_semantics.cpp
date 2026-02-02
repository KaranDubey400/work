#include <iostream>
#include <vector>
#include <utility> 

using namespace std;

int main() {
   
    vector<int> vector1 = {1, 2, 3, 4, 5};
    
    cout << "Size of vector1 is -" << vector1.size() << endl;

    cout << "\nAfter copying" << endl;

    
    vector<int> vector2 = move(vector1);

    cout << "\nSize of vector1 is -" << vector1.size() << endl;
    cout << "\nSize of vector2 is -" << vector2.size() << endl;

    return 0;
}