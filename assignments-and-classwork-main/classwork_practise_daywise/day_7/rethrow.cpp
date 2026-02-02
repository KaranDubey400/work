#include <iostream>
using namespace std;

int main()
{
    try
    {
        try
        {
            throw 80;
        }
        catch (int n)
        {
            throw;   // rethrow the same exception
        }
    }
    catch (int n)
    {
        cout << endl << "Caught an int- " << n << endl;
    }

    return 0;
}
