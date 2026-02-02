#include <iostream>
using namespace std;

class fun
{
    public:
        void operator () ()
        {
            cout << "\nTest of functors...\n";
        }
};

int main()
{
    fun f;
    f(); 
    
    return 0;
}