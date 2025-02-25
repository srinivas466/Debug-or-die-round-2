#include <iostream>
using namespace std;

class Buffer {
public:
    Buffer(size_t size) : size(size), data(new char[size]) {}
    ~Buffer() { delete[] data; }

    
    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

   
    Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
    }

  
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;  
            size = other.size;
            data = other.data; 
           
        }
        return *this;
    }

    void print() const { cout << "Buffer size: " << size << endl; }
private:
    size_t size;
    char* data;
};

int main() {
    Buffer buf1(10);
    Buffer buf2(20);
    buf2 = std::move(buf1);

    return 0;
}
