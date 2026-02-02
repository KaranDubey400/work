#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char name[50];

public:
   
    Student() {
        strcpy(name, "Unknown");
    }

   
    Student(const char* n) {
        strcpy(name, n);
    }

    void display() {
        cout << name << endl;
    }
};

int main() {
    char name[50];
    cin.getline(name,50);

    Student s2;     
    s2.display();     

    Student s1(name);  
    s1.display();      

    return 0;
}
