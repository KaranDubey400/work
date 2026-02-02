#include <iostream>
#include <future>
#include <thread>
using namespace std;

void calculateFactorial(promise<unsigned long long>&& factPromise, int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    factPromise.set_value(result);
}

int main() {
    int num = 10;
    std::promise<unsigned long long> factPromise;
    std::future<unsigned long long> factFuture = factPromise.get_future();

    std::thread t(calculateFactorial, std::move(factPromise), num);

    std::cout << "Factorial of " << num << " is: " << factFuture.get() << std::endl;

    t.join();
    return 0;
}