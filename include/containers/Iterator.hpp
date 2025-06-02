#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <typename T>
class Iterator {
  T* ptr;

 public:
  explicit Iterator(T* p = nullptr) : ptr(p) {}

  T& operator*() const { return *ptr; }
  Iterator& operator++() {
    ++ptr;
    return *this;
  }
  bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
};

#endif