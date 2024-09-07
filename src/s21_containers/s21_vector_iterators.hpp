#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_VECTOR_ITERATORS_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_VECTOR_ITERATORS_HPP_
#include <algorithm>
#include <iostream>
namespace s21 {
template <typename T>
class VectorIterator {
 public:
  VectorIterator() = default;
  explicit VectorIterator(T* pointer) : pointer_(pointer){};
  T* base() { return pointer_; };
  T operator*() { return *pointer_; };
  VectorIterator& operator++();
  VectorIterator operator++(int);
  VectorIterator& operator--();
  VectorIterator operator--(int);
  bool operator==(VectorIterator iter2) { return iter2.pointer_ == pointer_; };
  bool operator!=(VectorIterator iter2) { return this != iter2; };

 private:
  T* pointer_;
};

template <typename T>
class VectorConstIterator {
 public:
  VectorConstIterator<T>() = default;
  explicit VectorConstIterator<T>(const T* pointer) : pointer_(pointer){};
  const T* base() { return pointer_; };
  const T operator*() { return *pointer_; };
  VectorConstIterator<T>& operator++();
  VectorConstIterator<T> operator++(int);
  VectorConstIterator<T>& operator--();
  VectorConstIterator<T> operator--(int);
  bool operator==(const VectorConstIterator<T> iter2) {
    return iter2.pointer_ == pointer_;
  };
  bool operator!=(const VectorConstIterator<T> iter2) { return this != iter2; };

 private:
  const T* pointer_;
};

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator++() {
  ++pointer_;
  return *(this);
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator--() {
  --pointer_;
  return *(this);
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator++(int) {
  T* tmp = pointer_;
  ++pointer_;
  return VectorIterator<T>(tmp);
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator--(int) {
  T* tmp = pointer_;
  --pointer_;
  return VectorIterator<T>(tmp);
}

template <typename T>
VectorConstIterator<T>& VectorConstIterator<T>::operator++() {
  ++pointer_;
  return *(this);
}

template <typename T>
VectorConstIterator<T>& VectorConstIterator<T>::operator--() {
  --pointer_;
  return *(this);
}

template <typename T>
VectorConstIterator<T> VectorConstIterator<T>::operator++(int) {
  const T* tmp = pointer_;
  ++pointer_;
  return VectorConstIterator<T>(tmp);
}

template <typename T>
VectorConstIterator<T> VectorConstIterator<T>::operator--(int) {
  const T* tmp = pointer_;
  --pointer_;
  return VectorConstIterator<T>(tmp);
}
}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_VECTOR_ITERATORS_HPP_