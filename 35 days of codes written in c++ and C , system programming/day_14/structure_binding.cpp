#include <iostream>
#include <tuple>   
#include <string>  

using namespace std;

int main() 
{
    
    tuple<string, int, double> person("Abc", 32, 70.5);

   
    auto [name, age, weight] = person;

    cout << "\n person is-" << name;
    cout << "\n age is-" << age;
    cout << "\n weight is-" << weight << endl;

    return 0;
}