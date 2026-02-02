#include <iostream>
#include <stdexcept>   
using namespace std;

int main()
{
    try
    {
        int num = 0, denom = 0;

        cout << "enter a number followed by denominator: ";
        cin >> num >> denom;

        if (denom == 0)
        {
            throw runtime_error("tried to divide by 0\n");
        }

        cout << endl<<"result of division is " << num / denom << endl;
    }
    catch (const exception& e)
    {
        cout << endl << "Caught an exception " << e.what() << endl;
    }

    return 0;
}
