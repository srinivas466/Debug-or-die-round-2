#include <iostream>
#include <vector>
#include <thread>
using namespace std;

vector<int> shared;

void pushData() {
    for (int i = 0; i < 1000; ++i) {
        shared.push_back(i); // Bug: Unsynchronized access
    }
}

int main() {
    thread t1(pushData);
    thread t2(pushData);
    t1.join();
    t2.join();
    cout << "Vector size: " << shared.size() << endl;
    return 0;
}


