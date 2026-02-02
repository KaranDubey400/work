#include <iostream>
#include <functional> 

using namespace std;

class test
{
public:
    void show(int n)
    {
        cout << "\nI am a member function\n";
    }

    
    static void stat(int a)
    {
        cout << "\nI am a static function. Received value: " << a << "\n";
    }
};

void global(double d)
{
    cout << "\nI am a global function\n";
}

int main()
{
    test t1;

  
    t1.show(10);
    t1.stat(5);  
    test::stat(190);
    global(90.0);

    cout << "\nUsing invoke method of c++ 17 to call diff functions\n";


    invoke(&test::show, t1, 10);

    
    invoke(&test::stat, 100);

   
    invoke(global, 90.5);

    return 0;
}