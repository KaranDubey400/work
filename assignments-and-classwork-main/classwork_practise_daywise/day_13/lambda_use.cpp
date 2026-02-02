#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vc) {
    
    for_each(vc.begin(), vc.end(), [](int a) {
        cout << a << " ";
    });
    cout << endl;
}

int main() {
 
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    int r = add(100, 200);
    cout << "result of add " << r << endl;


    
    int num1 = 10, num2 = 20;

    
    auto show = [&]() {
        num1 += 20; 
        num2 += 50; 
        cout << "inside show() - num1 " << num1 << ", num2: " << num2 << endl;
    };

    show();


  
    vector<int> v{4, 1, 3, 5, 1, 2, 7, 3};
    cout << "vector elements ";
    print(v);

    return 0;
}