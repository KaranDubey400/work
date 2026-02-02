#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> count(0);

void incr()
{
    for (int i = 0; i < 100000; i++)
    {
        count++;   
    }
}

int main()
{
    thread t1(incr);
    thread t2(incr);

    t1.join();
    t2.join();

    cout << "\nCounter: " << count << endl;
    return 0;
}
