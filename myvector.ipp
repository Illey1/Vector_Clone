#ifndef MYVECTOR_IPP
#define MYVECTOR_IPP

#include "myvector.h"

template <typename T>
MyVector<T>::MyVector(const MyVector& other) : _size(other._size), _capacity(other._capacity), data(nullptr) {
  if (_capacity == 0) { return; }
  data = new T[_capacity];
  try {
    for (size_t i = 0; i < _size; ++i) {
      data[i] = other.data[i];
    }
  }
     catch (...) { //if an exception occurs, just create an empty vector
     delete[] data;
     data = nullptr;
     _size = _capacity = 0;
     throw;
    }
} //copy constructor

template <typename T>
MyVector<T>::MyVector(MyVector&& other) : _size(other._size), _capacity(other._capacity), data(other.data) {
  other._size = 0;
  other._capacity = 0;
  other.data = nullptr;
} //move constructor

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {

} // copy assignment

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) {

} //move assignment

//element access
template <typename T>
T& MyVector<T>::operator[](size_t index) {
  if (index >= _size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

template <typename T>
const T& MyVector<T>::operator[](size_t index) const {
  if (index >= _size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

template <typename T>
T& MyVector<T>::at(size_t index) {
  if (index >= _size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

template <typename T>
const T& MyVector<T>::at(size_t index) const {
  if (index >= _size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

template <typename T>
T& MyVector<T>::front() {
  if (_size <= 0) {
    throw std::out_of_range("Vector is empty");
  }
  return data[0];
}

template <typename T>
T& MyVector<T>::back() {
  if (_size <= 0) {
    throw std::out_of_range("Vector is empty");
  }
  return data[_size - 1];
}

//capacity
template <typename T>
size_t MyVector<T>::size() const { return _size; }

template <typename T>
size_t MyVector<T>::capacity() const { return _capacity; }

template <typename T>
bool MyVector<T>::empty() const { return _size == 0; }

//modifiers
template <typename T>
void MyVector<T>::push_back(const T& value) {
  if (_size == _capacity) {
    size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2; //doubles capacity, sets to 1 if 0.
    reallocate(new_capacity);
  }
  data[_size++] = value; //add value to vector
}

template <typename T>
void MyVector<T>::push_back(T&& value) {
  if (_size == _capacity) {
    size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
    reallocate(new_capacity);
  }
  data[_size++] = std::move(value);
}

template <typename T>
void MyVector<T>::pop_back() {
  if (_size > 0) {
    --_size; //no need to remove element. will be overwritten
  }
}

template <typename T>
void MyVector<T>::clear() { // no need to change elements, since any access outside of _size will trigger exception
  _size = 0;
}

template <typename T>
void MyVector<T>::reserve(size_t new_cap) {
    if (new_cap > _capacity) {
        reallocate(new_cap);
    }
}


template <typename T>
void MyVector<T>::resize(size_t new_size, const T& value) {
    if (new_size > _capacity) {
        // Case 1: need more space
        reallocate(new_size);
        for (size_t i = _size; i < new_size; ++i) {
            data[i] = value;
        }
        _size = new_size;
    }
    else if (new_size > _size) {
        // Case 2: expand within capacity
        for (size_t i = _size; i < new_size; ++i) {
            data[i] = value;
        }
        _size = new_size;
    }
    else if (new_size < _size) {
        // Case 3: shrink
        _size = new_size;
    }
}



//iterators
template <typename T>
T* MyVector<T>::begin() {
  if (empty()) { return nullptr; }
  return data;
}

template <typename T>
T* MyVector<T>::end() {
  if (empty()) { return nullptr; }
  return data + _size;
}

template <typename T>
const T* MyVector<T>::begin() const {
  if (empty()) { return nullptr; }
  return data;
}

template <typename T>
const T* MyVector<T>::end() const {
  if (empty()) { return nullptr; }
  return data + _size;
}

#endif