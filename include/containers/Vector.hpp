#ifndef CUSTOM_VECTOR
#define CUSTOM_VECTOR

#include <stdexcept>

#include "Iterator.hpp"

template <typename T> class Vector {
  T *data = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;

  void reallocate(size_t new_capacity) {
    T *new_data = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity_ = new_capacity;
  }

public:
  using Iterator = ::Iterator<T>;

  explicit Vector(size_t count = 0, const T &value = T()) {
    if (count > 0) {
      data = new T[count];
      capacity_ = count;
      size_ = count;
      for (size_t i = 0; i < count; ++i) {
        data[i] = value;
      }
    }
  }

  Vector(const Vector &other) : data(nullptr), size_(0), capacity_(0) {
    if (other.size_ > 0) {
      data = new T[other.capacity_];
      size_ = other.size_;
      capacity_ = other.capacity_;
      for (size_t i = 0; i < size_; ++i) {
        data[i] = other.data[i];
      }
    }
  }

  Vector &operator=(const Vector &other) {
    if (this != &other) {
      delete[] data;
      data = nullptr;
      size_ = 0;
      capacity_ = 0;

      if (other.size_ > 0) {
        data = new T[other.capacity_];
        size_ = other.size_;
        capacity_ = other.capacity_;
        for (size_t i = 0; i < size_; ++i) {
          data[i] = other.data[i];
        }
      }
    }
    return *this;
  }

  ~Vector() { delete[] data; }

  void push_back(const T &value) {
    if (size_ >= capacity_) {
      reallocate(capacity_ == 0 ? 4 : capacity_ * 2);
    }
    data[size_++] = value;
  }

  T &operator[](size_t index) {
    if (index >= size_)
      throw std::out_of_range("Index out of range");
    return data[index];
  }

  const T &operator[](size_t index) const {
    if (index >= size_)
      throw std::out_of_range("Index out of range");
    return data[index];
  }

  size_t size() const { return size_; }

  bool empty() const { return size_ == 0; }

  T &back() {
    if (empty())
      throw std::out_of_range("Vector is empty");
    return data[size_ - 1];
  }

  void clear() {
    delete[] data;
    data = nullptr;
    size_ = 0;
    capacity_ = 0;
  }

  Iterator begin() { return Iterator(data); }
  Iterator end() { return Iterator(data + size_); }
};

#endif