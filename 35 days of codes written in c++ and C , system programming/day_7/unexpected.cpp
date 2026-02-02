#include <iostream>
using namespace std;

int main()
{
    try
    {
        try
        {
            throw 10;
        }
        catch(char ch)
        {
            cout << "catching char";
        }
    }
    catch(int n)
    {
        cout << endl << "caught an int" << endl;
    }
}

