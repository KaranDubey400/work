#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int balance = 1000;
mutex mt;


void deposit(int amount){

    lock_guard<mutex> lock(mt); 

    balance += amount;
}


void withdraw(int amount){

    lock_guard<mutex> lock(mt); 

    balance -= amount;
}

int main()
{
    
    thread t1(deposit, 500);   
    thread t2(withdraw, 200);  
    thread t3(deposit, 300);   
    thread t4(withdraw, 100); 


    t1.join();
    t2.join();
    t3.join();
    t4.join();

    
    cout << "final balance is " << balance << endl;

    return 0;
}
