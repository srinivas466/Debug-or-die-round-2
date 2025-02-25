#include <iostream>
#include <memory>
using namespace std;

class B;

class A {
public:
    shared_ptr<B> b_ptr;
    ~A() { cout << "A destroyed" << endl; }
};

class B {
public:
    shared_ptr<A> a_ptr;
    ~B() { cout << "B destroyed" << endl; }
};

int main() {
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
   
    return 0;
}

