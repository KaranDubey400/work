#include <iostream>
using namespace std;

class bill
{
    char name[30];
    int unit;
    float total;

public:
    void get()
    {
        cout << "person name ";
        cin >> name;
        cout << "enter the unit consumed";
        cin >> unit;
    }

    void calc_bill()
    {
        if(unit <= 100)
        {
            total = unit * 1.20;
        }
        else if(unit <= 200)
        {
            total = (100 * 1.20) + (unit - 100) * 2;
        }
        else
        {
            total = (100 * 1.20) + (100 * 2) + (unit - 200) * 3;
        }
    }

    void put()
    {
  cout <<endl<< "person_name  " << name<<",  units  "<<unit<<"  total bil  "<<total<<endl;
       
    }
};

int main()
{
    bill s1;
    s1.get();
    s1.calc_bill();
    s1.put();

    return 0;
}
