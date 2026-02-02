#include <iostream>
using namespace std;

class divi
{
    private:
    int num, denom;

public:
  
    divi(int i, int j)
    {
        if (j == 0)
        {
            throw "division not allowed";
        }
        num = i;
        denom = j;
    }

    void show()
    {
        cout << "div is " << (num / denom) << endl;
    }
};

int main()
{
    int num = 0, denom = 0;

    cout << "enter a number followed by denominator ";
    cin >> num >> denom;

    try
    {
        divi s1(num, denom);  
        s1.show();
    }
    catch (const char* msg)
    {
        cout << "exception caught" << msg << endl;
    }

    return 0;
}
