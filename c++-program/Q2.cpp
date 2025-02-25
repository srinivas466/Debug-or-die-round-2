#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructed" << endl; }
    
    ~Base() { cout << "Base destructed" << endl; }
};

class Derived : public Base {
public:
    Derived() {
        data = new int[10];
        cout << "Derived constructed" << endl;
    }
    ~Derived() {
        delete[] data;
        cout << "Derived destructed" << endl;
    }
private:
    int* data;
};

int main() {
    Base* obj = new Derived();
    delete obj; 
    return 0;
}

