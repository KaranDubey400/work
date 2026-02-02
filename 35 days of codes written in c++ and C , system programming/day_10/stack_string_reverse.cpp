#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
    char name[30];
    cin >> name;
     int len = strlen(name);

    stack<char> s;
   

    for (int i = 0; i < len; i++) {
        s.push(name[i]);
    }

    int k = 0;
    while (!s.empty()) {
        name[k++] = s.top();
        
        s.pop();
    }

    cout << name;
    
}