#include <iostream>
using namespace std;

class Student 
{
    private:
    int roll;
    float sub1, sub2, sub3;

    public:
    void setRoll(int k) 
    {
        roll = k;
    }

    void input() 
    {
        cout << "enter 3 subject marks "<<endl;
        cin >> sub1 >> sub2 >> sub3;
    }

    void display()
     {
        float avg = (sub1 + sub2 + sub3) / 3;
        cout << "roll_n  " << roll << endl;
        cout << "avg mark " << avg  << endl;
    }
};

int main() {
    Student s[3];

    for (int i = 0; i < 3; i++) 
    {
        s[i].setRoll(i + 1);
        s[i].input();
    }

    cout << "student"<<endl;
    for (int i = 0; i < 3; i++) 
    {
        s[i].display();
    }

    return 0;
}
