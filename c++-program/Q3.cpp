#include <iostream>
using namespace std;

int& getNumber() {
    int x = 10;
    return x; 
}

int main() {
    int &num = getNumber();
    cout << num << endl; 
    return 0;
}

//Hello, World!

