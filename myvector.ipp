#ifndef MYVECTOR_IPP
#define MYVECTOR_IPP

#include "myvector.h"

template <typename T>
MyVector::MyVector(const MyVector& other) : _size(other._size), _capacity(other._size), data(nullptr) {
  if (_capacity = 0) { return; }
  data = new T[_capacity];
  try {
    for (size_t i = 0; i < _size; ++i) {
      data[i] = other.data[i];
    } catch (...) { //if an exception occurs, just create an empty vector
      delete[] data;
      data = nullptr;
      _size = _capacity = 0;
      throw;
    }
  }
} //copy constructor

template <typename T>
MyVector::MyVector(MyVector&& other); //move constructor

template <typename T>
MyVector& MyVector::operator=(const MyVector& other); // copy assignment

template <typename T>
MyVector& MyVector::operator=(MyVector&& other); //move assignment

//element access
template <typename T>
T& MyVector::operator[](size_t index) {
  if (index >= _size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

template <typename T>
const T& MyVector::operator[](size_t index) {
  if (index >= _size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

template <typename T>
T& MyVector::at(size_t index);

template <typename T>
const T& MyVector::at(size_t index) const;

template <typename T>
T& MyVector::front;

template <typename T>
T& MyVector::back;

//capacity
template <typename T>
size_t MyVector::size() const { return _size; }

template <typename T>
size_t MyVector::capacity() const { return _capacity; }

template <typename T>
bool MyVector::empty() const { return _size == 0; }

//modifiers
template <typename T>
void MyVector::push_back(const T& value) {
  if (_size == _capacity) {
    size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2; //doubles capacity, sets to 1 if 0.
    resize(new_capacity);
  }
  data[_size++] = value; //add value to vector
}

template <typename T>
void MyVector::push_back(T&& value);

template <typename T>
void MyVector::pop_back() {
  if (_size > 0) {
    --_size; //no need to remove element. will be overwritten
  }
}

template <typename T>
void MyVector::clear();

template <typename T>
void MyVector::reserve(size_t new_cap);

template <typename T>
void MyVector::resize(size_t new_size, const T& value = T());

//iterators
template <typename T>
T* MyVector::begin();

template <typename T>
T* MyVector::end();

template <typename T>
const T* MyVector::begin() const;

template <typename T>
const T* MyVector::end() const;

#endif