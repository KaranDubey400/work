#include <iostream>
#include <cstring>
using namespace std;


class Print {
public:
    
    void print(int n, char c)
     {
        cout << "integer " << n << ", character " << c << endl;
    }

    
    void print(char c, int n)
     {
        cout << "character " << c << ", integer" << n << endl;
    }
};

int main() {
    Print s;
    s.print(10, 'A');  
    s.print('B', 20);   

    return 0;

}
