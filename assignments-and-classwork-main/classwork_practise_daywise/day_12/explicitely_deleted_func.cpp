#include <iostream>
using namespace std;

class test
{
public:
    test(int x)
    {
        cout << "\nInt parameter\n";
    }

    test(double) = delete;  
};

int main()
{
    test t1(10);     
    test t2(100.5);  
}
