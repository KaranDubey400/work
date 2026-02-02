#include <iostream>
using namespace std;

template<typename T1, typename T2>
class test
{
    private:
        T1 var1;
        T2 var2;

    public:
        test(T1 v1, T2 v2)
        {
            var1 = v1;
            var2 = v2;
        }

        void show()
        {
            cout << "\nvar 1 is-" << var1 << "  var2 is-" << var2 << endl;
        }
};

int main()
{
    
    test<int, double> t1(100, 2.3);
    t1.show();

    test<char, float> t2('A', 8.1f);
    t2.show();

    return 0;
}