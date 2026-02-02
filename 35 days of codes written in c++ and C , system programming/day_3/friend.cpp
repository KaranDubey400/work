#include <iostream>
using namespace std;

class rect;   // forward declaration inform the complier about the class

class Circle {
    double area;

public:
    Circle(double r) {
        area = 3.14159 * r * r;   // area of circle
    }
   
     // and to make a class to become friend of another class 
// we can write friend 
    friend class rect ;
   

    friend void compare(rect&, Circle&);
};

class rect {
    double area;

public:
    rect(double l) {
        area = l;   // assume already calculated area
    }

    friend void compare(rect&, Circle&);
};

void compare(rect& rr, Circle& cc) {
    if (rr.area > cc.area) {
        cout << "Rectangle has more area\n";
    }
    else if (rr.area < cc.area) {
        cout << "Circle has more area\n";
    }
    else {
        cout << "Both have same area\n";
    }
}

int main() {
    rect r1(80.2);
    Circle c1(4.6);

    compare(r1, c1);
    return 0;
}
