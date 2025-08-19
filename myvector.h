#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data;
    size_t _size;
    size_t _capacity;

    void resize(size_t capacity);


public:
    MyVector() : data(nullptr), _size(0), _capacity(0) {} //default

    ~MyVector() {
      delete[] data; //destructor
    }

    MyVector(const MyVector& other); //copy constructor

    MyVector(MyVector&& other); //move constructor

    MyVector& operator=(const MyVector& other); // copy assignment

    MyVector& operator=(MyVector&& other); //move assignment

    //element access
    T& operator[](size_t index);
    const T& operator(size_t index);
    T& at(size_t index);
    const T& at(size_t index) const;
    T& front;
    T& back;

    //capacity
    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    //modifiers
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void clear();
    void reserve(size_t new_cap);
    void resize(size_t new_size, const T& value = T());

    //iterators
    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
}

#include "myvector.ipp"

#endif