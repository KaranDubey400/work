#include <iostream>
#include <cstring>
using namespace std;

class programming {

    private:
    char name[100];

     public:

   
    programming() 
    {
        strcpy(name, "i love programming languages");
    }

    
    programming(const char* n)
     {
        sprintf(name, "I love %s", n);
    }

    void display() 
    {
        cout << name << endl;
    }
};

int main() {
    programming s1;      
    s1.display();

    programming s2("C++"); 
    s2.display();

    return 0;
}
