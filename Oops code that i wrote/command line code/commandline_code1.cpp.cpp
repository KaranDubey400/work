#include <iostream>
#include <cstdlib>
using namespace std;

class number
{
    private:

    int num;


    public:
    
    number() : num(0) {

    }

    void set(int x)
    {
        num = x;
    }

    int operator+(const number &x)
    {
        return num + x.num;
    }

    int operator-(const number &x)
    {
        return num - x.num;
    }

    int operator*(const number &x)
    {
        return num * x.num;
    }

    int operator/(const number &x)
    {
        if (x.num == 0)
        {
            cout << "error: division by zero";
            return 0;
        }
        return num / x.num;
    }

    int operator%(const number &x)
    {
        if (x.num == 0)
        {
            cout << "error: modulo by zero";
            return 0;
        }
        return num % x.num;
    }
};

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "usage: <num1> <num2> <operator>";
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    char c = argv[3][0];

    number s1, s2;
    s1.set(a);
    s2.set(b);

    switch (c)
    {
    case '+':
        cout << s1 + s2;
        break;
    case '-':
        cout << s1 - s2;
        break;
    case '*':
        cout << s1 * s2;
        break;
    case '/':
        cout << s1 / s2;
        break;
    case '%':
        cout << s1 % s2;
        break;
    default:
        cout << "invalid operator";
    }

    return 0;
}
