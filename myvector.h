#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data;
    size_t _size;
    size_t _capacity;


public:
    MyVector() : data(nullptr), _size(0), _capacity(0) {} //default

    ~MyVector() {
      delete[] data; //destructor
    }

    MyVector(const MyVector& other); //copy constructor

    MyVector(MyVector&& other); //move constructor

    MyVector& operator=(const MyVector& other); // copy assignment

    MyVector& operator=(MyVector&& other); //move assignment
}