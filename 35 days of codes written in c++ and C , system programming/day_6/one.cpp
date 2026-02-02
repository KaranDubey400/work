#include <iostream>
#include <cstdlib>
using namespace std;

class number {
private:
    int num;

public:
   
    number() {
        num = 0;
    }

   
    void set(int n) {
        num = n;
    }

   
    int operator+(number m) {
        return num + m.num;
    }

    int operator-(number m) {
        return num - m.num;
    }

    int operator*(number m) {
        return num * m.num;
    }

    int operator/(number m) {
        return num / m.num;
    }

    int operator % (number m) {
        return this->num % m.num;
    }
};

int main(int argc, char **argv) {

    if (argc != 4) {
        cout << " invalid or 0arg or > " << endl;
        return 1;
    }

    number s1, s2;

    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    char sym = argv[3][0];

    s1.set(n1);
    s2.set(n2);

    int result;

    if (sym == '+') 
    {
        result = s1 + s2;
    }
    
    else if (sym == '-')
    {
        result = s1-s2;
    }
    
    else if (sym == '*')
    {
        result = s1*s2;
    }
    
    else if (sym == '/') {
        result = s1/s2;
    }
    
    else if (sym == '%') {
        result = s1% s2;
    }else 
    {
        return 1;
    }

    cout << "resut" << result << endl;

    return 0;
}

   
