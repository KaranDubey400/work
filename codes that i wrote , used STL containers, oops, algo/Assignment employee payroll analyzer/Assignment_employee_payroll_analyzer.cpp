#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Employee {
    int empId;
    string name;
    double salary;
};

int main()
 {
    int n;
    cout << "no. of employee ";
    cin >> n;

    vector<Employee> employees;

    employees.reserve(n);

    for (int i = 0; i < n; ++i)
     {
        Employee s1;

        cout << "empid, name ,salary";

        cin >> s1.empId >> s1.name >> s1.salary;

        employees.push_back(s1);
    }

   
    auto minmax = minmax_element(

        employees.begin(), employees.end(),  [](const Employee& one, const Employee& two) {
              
            return one.salary < two.salary;
        }
    );

    auto minIt = minmax.first;

      auto maxIt = minmax.second;

        cout << "\n  lowest paid " << minIt->name << " ( " << minIt->salary << ")";
    cout << "\n high paid " << maxIt->name << " (" << maxIt->salary << ")"<<endl;

 
    double total = accumulate( employees.begin(), employees.end(), 0.0,
    [](double sum, const Employee& s1) {

            return sum + s1.salary;

        }

    );

    double avg = total / employees.size();

    
    for_each(employees.begin(), employees.end(), [avg](Employee& s1) {
          
        if (s1.salary < avg) {

                s1.salary *= 1.10;

            }


        }

    );

    cout << "\n new salaty \n";
    for ( auto& k : employees) {
        cout << k.empId << " " << k.name << " " << k.salary << "\n";
    }

   
}
