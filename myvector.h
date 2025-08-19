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

    void resize(size_t capacity) {
      T* new_data = new T[new_capacity]; //dynamic array to be filled with old data
      for (size_t i = 0; i < _size; ++i) {
        new_data[i] = data[i];
      }

      delete[] data; //delete old array and update member variables
      data = new_data;
      _capacity = new_capacity;
    }


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
    const T& operator[](size_t index);
    T& at(size_t index);
    const T& at(size_t index) const;
    T& front();
    T& back();

    //capacity
    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    //modifiers
    /*
    * standard push_back method. Accounts for if vector is full
    * @param value - reference to value to be added. (pass by const reference to handle bigger data types)
    */
    void push_back(const T& value);

    /*
    *
    */
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
};

#include "myvector.ipp"

#endif