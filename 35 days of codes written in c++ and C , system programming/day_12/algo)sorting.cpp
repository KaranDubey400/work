#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct employee
{
    string name;
    double salary;
};

bool comp(const employee &x, const employee &y)
{
    return x.salary > y.salary;
}

int main()
{
    vector<employee> v1 = {
        {"abc", 70000},
        {"xyz", 61000},
        {"mno", 44000},
        {"bcs", 52000}
    };

    sort(v1.begin(), v1.end(), comp);

    for (auto i : v1)
    {
        cout << "name - " << i.name << "  salary is - " << i.salary << endl;
    }

    return 0;
}
