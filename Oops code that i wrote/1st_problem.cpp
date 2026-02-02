#include <iostream>
#include <string>
using namespace std;

class employee {
private:
    string name;
    float salary;
    string joiningdate;

public:
    void input() {
       getline(cin,name);
        cin >> salary;
        
        getline(cin,joiningdate);
    }

    void display() {
        cout  << name << endl;
        cout  << salary << endl;
        cout << joiningdate << endl;
        cout<<endl;
       
    }
};

int main() {
    cout << "10  employee " << endl;
    employee s1[10];
    

    for (int i = 0; i < 10; i++) {
        s1[i].input();
    }

    cout  << endl;
    for (int i = 0; i < 10; i++) {
        s1[i].display();
    }

    return 0;
}

