#include <iostream>
#include <thread>
using namespace std;

class LazySingleton {
public:
    static LazySingleton* getInstance() {
        if (!instance) {          // No synchronization: race condition here!
            instance = new LazySingleton();
        }
        return instance;
    }
    void doSomething() { cout << "Doing something." << endl; }
private:
    LazySingleton() { cout << "Singleton created." << endl; }
    static LazySingleton* instance;
};

LazySingleton* LazySingleton::instance = nullptr;

void threadFunc() {
    LazySingleton::getInstance()->doSomething();
}

int main() {
    thread t1(threadFunc);
    thread t2(threadFunc);
    t1.join();
    t2.join();
    return 0;
}


