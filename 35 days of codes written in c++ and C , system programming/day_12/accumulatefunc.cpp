#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool check(int x)
{
    return x % 2 == 0;
}

int main()
{
    vector<int> v1 = {10, 20, 30, 41, 50};

    if (all_of(v1.begin(), v1.end(), check))
        cout << "\nAll numbers in vector are even\n";
    else
        cout << "\nAll numbers in vector are not even\n";

    int tot = accumulate(v1.begin(), v1.end(), 0);
    cout << "\nSum of all vector elements is-" << tot << endl;

    return 0;
}
