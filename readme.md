#  my C++ & System Programming learning 

## 📌 Repository Overview
This repository documents a  learning journey into  **Advanced C++** and bit of sys programming ,  
It contains  projects and exercises, covering  fundamental object oriented design to Inter process communication (IPC) systems using shared memory and multi threading.

used C++ and C 


###  built Real-Time Telemetry Pipeline (C / POSIX)
A high-performance system aimed at handling sensor data in a concurrent environment.
*   **Architecture**: Uses **Producer-Consumer** model with multiple processes.
*   **Core Technology**: 
    *   **POSIX Shared Memory** (`shm_open`, `mmap`) for zero-copy data exchange.
    *   **Synchronization**: `pthread_rwlock_t` (Read-Write Locks) and `pthread_mutex_t` to ensure thread safety.
    *   **Data Structure**: Custom **Shared Memory Linked List** to manage event nodes dynamically within a fixed memory block.
*   **Key Files**: `telemetry.h`, `monitor.c`, `analyzer.c`, `generator.c` (located in *35 days/day_26-29*).

###  Employee Payroll Analyzer (C++ STL)
A data processing tool utilizing the standard template Library (STL) to manage and analyze employee records.
*   **Features**: handles large datasets using containers.
*   **Concepts**: Vectors, Maps, and Algorithms.

### 3. Student Course Management System
A complete management utility for academic tracking, demonstrating oops principles and STL usage.

## 🛠 Technical Concepts Covered

### System Programming & Concurrency
*   **Multi-threading**: Thread creation, detachment, and parameter passing (`pthread`, `std::thread`).
*   **Synchronization**: Handling Race Conditions using Mutexes, Lock Guards, and Atomic operations,  semaphores.
*   **Advanced Threading**: Futures, Promises, and Thread Interleaving.
*   **IPC (Inter-Process Communication)**: Deep dive into Shared Memory mechanisms and memory mapping.

### Object-Oriented Programming (OOP)
*   **Polymorphism**: Static vs. Dynamic binding, Virtual Functions, and V-Tables.
*   **Design Patterns**: Abstract Classes, Pure Virtual Functions, and Encapsulation.
*   **Memory Management**: Custom constructors, destructors, and deep vs. shallow copy.

### Algorithms & STL
*   **Containers**: Heavy usage of `std::vector`, `std::map`, and `std::list`.
*   **String Manipulation**: complex parsing and formatting logic.
*   algo - find_if , erase , remove, sort, for_each , range based loops +


*   **/35 days of codes...**: The core timeline of the learning journey.
    *   *Days 1-14*: Foundations of C/C++ and OOP.
    *   *Days 15-25*: Multi-threading, Concurrency, and Synchronization.
    *   *Days 26-29*: The **Telemetry Pipeline** ,
    *   *Days 30-33* :  **Car simulation, terminal based **
*   **/Oops code that i wrote**: Dedicated exercises for mastering OOP concepts (Constructors, Inheritance).
*   **/codes that i wrote...**: Application-level projects using STL and Algorithms (Payroll, Course Management).

## 💡 How to Build & Run
i used Ubuntu linux , 
Most C projects in this repo can be compiled using GCC/Clang:
```bash
# Example for Telemetry Monitor
gcc -o monitor monitor.c -lpthread -lrt
./monitor
```
C++ projects can be built with G++:
```bash
g++ -o app main.cpp
./app
```

ALSo used Makefile to compile files and create single executable
