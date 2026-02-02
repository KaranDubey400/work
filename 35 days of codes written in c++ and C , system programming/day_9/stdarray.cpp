//assigned in the class 
#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    int roll;
    float cgpa;

public:
    
    Student() {
        roll = 0;
        cgpa = 0.0;
    }

    Student(int r, float c) {
        roll = r;
        cgpa = c;
    }


    void input() {
        cout << "enter roll number ";
        cin >> roll;
        cout << "cgpa";
        cin >> cgpa;
    }

   
    void output() const {
        cout << "roll number " << roll << "cgpa " << cgpa << endl;
    }
};


void display(const vector<Student>& v) {
    cout << "student information ";
    for (const auto& s : v) {
        s.output();
    }
}

int main() {
    vector<Student> students;
    int n;

    cout << "how many students ";
    cin >> n;

   
    for (int i = 0; i < n; i++) {
        Student s;
        s.input();
        students.push_back(s);
    }

    display(students);

    
    cout << "insert new student at po 1";
    Student newStudent(999, 9.9);
    students.insert(students.begin() + 1, newStudent);

    display(students);

    
   cout<<" delete student "<<endl;
    students.erase(students.begin());

    display(students);

    return 0;
}
