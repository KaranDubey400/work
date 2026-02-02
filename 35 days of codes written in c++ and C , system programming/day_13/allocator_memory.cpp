#include <iostream>
#include <memory>

using namespace std;

int main() {
    // 1. Create the allocator object
    allocator<int> myaloc;

    // 2. Allocate raw memory for 5 integers
    // Note: This does NOT call constructors
    int* ptr = myaloc.allocate(5); 

    // 3. Input and Construct
    for (int i = 0; i < 5; i++) {
        int num;
        cout << "Enter num-" << (i + 1) << ": ";
        cin >> num;
        
        // myaloc.construct is deprecated in C++17/20. 
        // Modern C++ uses placement new or std::construct_at
        myaloc.construct(ptr + i, num); 
    }

    // 4. Display values
    cout << "Values stored: ";
    for (int i = 0; i < 5; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;

    // 5. Destroy objects
    // This calls the destructor for each element
    for (int i = 0; i < 5; i++) {
        myaloc.destroy(ptr + i);
    }

    // 6. DEALLOCATE (The Missing Step)
    // This actually frees the memory block back to the heap
    myaloc.deallocate(ptr, 5);

    return 0;
}