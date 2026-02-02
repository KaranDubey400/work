#include <iostream>
using namespace std;

class Parent {
public:
    Parent() {
        cout << "Parent Constructor" << endl;
    }

    ~Parent() {
        cout << "Parent Destructor" << endl;
    }
};

class Child : public Parent {
public:
    Child() {
        cout << "Child Constructor" << endl;
    }

    ~Child() {
        cout << "Child Destructor" << endl;
    }
};

class SubChild : public Child {
public:
    SubChild() {
        cout << "SubChild Constructor" << endl;
    }

    ~SubChild() {
        cout << "SubChild Destructor" << endl;
    }
};

int main() {
    SubChild obj;
    return 0;
}


// subchild child(int n1,int n2) : chid(a,b) ;
// child(int a,int b): parent(b);