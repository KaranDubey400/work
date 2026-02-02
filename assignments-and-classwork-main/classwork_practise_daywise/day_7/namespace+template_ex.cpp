#include <iostream>
using namespace std;


template <typename T>
void swapval(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

namespace n1
{
    int value = 10;
}


namespace n2
{
    int value = 20;
}

int main()
{
   
    cout << "2 val beforeswap" << n1::value << " "<< n2::value<< endl;

    swapval(&n1::value, &n2::value);

    cout << "2 val after swaping" << n1::value << " "<< n2::value<< endl;
      
    return 0;
}
