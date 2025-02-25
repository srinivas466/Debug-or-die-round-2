#include <iostream>
#include <stdexcept>
using namespace std;

void process() {
    int* buffer = new int[5];
   
    throw runtime_error("Error occurred");
    delete[] buffer;
}

int main() {
    try {
        process();
    } catch(const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

