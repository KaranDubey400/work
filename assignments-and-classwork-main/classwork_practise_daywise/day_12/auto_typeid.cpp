#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    auto a = 10;
    auto b = 2.3f;
    auto c = 4.5;
    auto d = 'X';
    auto ptr = &c;
    auto pptr = &ptr;

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
    cout << typeid(ptr).name() << endl;
    cout << typeid(pptr).name() << endl;

    return 0;
}
