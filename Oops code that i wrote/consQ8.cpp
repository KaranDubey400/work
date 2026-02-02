#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int age;
    string address;

public:
    
    Student() {
        name = "unknown";
        age = 0;
        address = "NA";
    }

    
    void setinfo(string n, int a) {
        name = n;
        age = a;
    }

   
    void setinfo(string n, int a, string addr) {
        name = n;
        age = a;
        address = addr;
    }

   
    void display() {
        cout << "name" << name
             << "age" << age
             << "address" << address << endl;
    }
};

int main() {
    Student s[10];  

 
    s[0].setinfo("rahul", 20);
    s[1].setinfo("amit", 21, "delhi");
    s[2].setinfo("sneha", 19);
    s[3].setinfo("pooja", 22, "mumbai");
    s[4].setinfo("karan", 23);
    s[5].setinfo("neha", 20, "pune");
    s[6].setinfo("ramsey", 21);
    s[7].setinfo("mnke", 22, "chennai");
    s[8].setinfo("mikos", 24);
    s[9].setinfo("meepna", 19, "bangalore");

    cout << "student info";
    for (int i = 0; i < 10; i++) {
        s[i].display();
    }

    return 0;
}
