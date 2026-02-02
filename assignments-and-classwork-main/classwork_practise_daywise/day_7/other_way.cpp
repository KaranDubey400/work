#include <iostream>
using namespace std;

void excpt_func()
{
    try
    {
        throw 100;   
    }
    catch (int i)
    {
        cout << "\nCaught an int... wrong value...\n";
        throw;      
    }
}

int main()
{
    try
    {
        excpt_func();
    }
    catch (int n)
    {
        cout << "\nException caught in main: " << n << endl;
    }

    return 0;
}
