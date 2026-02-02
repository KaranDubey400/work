#include <iostream>
using namespace std; 

class Student 
{
    private:
    double height; 

    public:
    void input() {
        cin >> height; 
    }
    
    double get_height() {
        return height; 
    }
    
    void display(double avg) 
    {
        cout << "avg height is " << avg << endl; 
    }
};

int main() 
{
    const int n = 3;
    Student s[n]; 
    
    double total = 0; 
    
    for(int i = 0; i < n; i++)
     {
        cout << "enter height of student" << (i + 1) << endl; 
        s[i].input(); 
        total += s[i].get_height(); 
    }
    
    double avg = total / n; 
    
   
    s[0].display(avg); 
    
    return 0;
}
