#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;


mutex mt;
condition_variable cv;
bool isready = false;


void consumer()
{
    unique_lock<mutex> lock(mt);
    cout << "\nconsumer thread... waiting...\n";

    
    cv.wait(lock, [] {
        return isready;
    });

    cout << "\nconsumer is awake and processing...\n";
}


void producer()
{

    this_thread::sleep_for(chrono::seconds(2));

    {
        lock_guard<mutex> lock(mt);
        isready = true;
        cout << "\nproducer has set isready to true...\n";
    }

    
    cv.notify_one();
}

int main()
{
    thread t1(consumer);
    thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}
