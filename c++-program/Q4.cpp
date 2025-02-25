
#include <iostream>
#include <atomic>
using namespace std;

struct Data {
    int x;
    int y;
  
};

int main() {
   
    atomic<Data> atomicData;  
    Data d{1, 2};
    atomicData.store(d);  
    Data d2 = atomicData.load();
    cout << d2.x << " " << d2.y << endl;
    return 0;
}


