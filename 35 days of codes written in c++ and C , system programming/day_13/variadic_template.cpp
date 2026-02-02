#include <iostream>

using namespace std;


void show() 
{
    cout << "\n i am an empty function and will be called last\n";
}


   template <typename T, typename... Types>

   void show(T var1, Types... var2) 
   {
   
    cout << endl << var1 << endl;

    
    show(var2...);
   }

     int main() 
   {
    
    show(1, 2.3f, 3.44, "  hello everyone");

    return 0;
   }