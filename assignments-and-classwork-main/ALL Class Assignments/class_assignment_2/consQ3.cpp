#include <iostream>
using namespace std;

class addamount {
private:
    int amount;

public:
    
    addamount() {
        amount = 50;
    }

    
     addamount(int add) {
        amount = 50 + add;
    }

    void display() {
        cout << "final amount in piggie bank--" << amount << endl;
    }
};

int main() {
     addamount s1;       
    s1.display();

     addamount s2(30);    
    s2.display();

    return 0;
}
