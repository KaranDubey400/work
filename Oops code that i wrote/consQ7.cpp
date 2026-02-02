#include <iostream>
using namespace std;

class Area {
public:
    
    void area(int side) {
        cout << "area  square: " << side * side << endl;
    }


    void area(int length, int breadth) {
        cout << "area rectangle: " << length * breadth << endl;
    }
};

int main() {
    Area s;

    s.area(5);        
    s.area(4, 6);     

    return 0;
}
