#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class sorting
{
    public:
        bool operator () (int a, int b)
        {
            return a > b;
        }
};

int main()
{
    vector<int> v = {7, 11, 5, 8, 3, 14, 12};
    
    cout << "\nVector elements before sorting\n";
    for(int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    
    
    sort(v.begin(), v.end(), sorting());
    
    cout << "\nVector elements after sorting\n";
    for(int i : v)
    {
        cout << i << " ";
    }
    
    return 0;
}