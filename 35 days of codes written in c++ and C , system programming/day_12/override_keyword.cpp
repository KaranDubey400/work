#include <iostream>
using namespace std;

class base
{
public:
    virtual void test()
    {
        cout << "\ni belong to base\n";
    }
};

class der : public base
{
public:
    void test(int a) override   
    {
        cout << "\ni belong to derived...\n";
    }
};

int main()
{
    base b;
    der d;
    cout << "\nCompiled successfully...\n";
}
