#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

mutex m1, m2;

void func1() {
    lock_guard<mutex> lock1(m1);
 
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(m2);
    cout << "func1 completed" << endl;
}

void func2() {
    lock_guard<mutex> lock1(m2);
    // Simulate work
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lock2(m1);
    cout << "func2 completed" << endl;
}

int main() {
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();
    return 0;
}

