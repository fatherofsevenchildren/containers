#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_ARRAY_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_ARRAY_TPP_
#include <algorithm>
#include <iostream>

#include "s21_vector_iterators.hpp"

namespace s21 {
template <typename T, size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using iterator = VectorIterator<T>;
  using const_iterator = VectorConstIterator<T>;

 public:
  array() = default;
  array(std::initializer_list<value_type> const &items);
  array(array &v);
  array(array &&v);
  array &operator=(array &&v);
  array operator=(const array &v);

  // ~array();
  reference operator[](size_type pos) { return array_[pos]; };
  const_reference at(size_type pos) const;
  const_reference back() { return array_[N - 1]; };
  const_reference front() { return array_[0]; };
  T *data() { return array_; };

  iterator begin() { return iterator(array_); };
  iterator end() { return iterator(array_ + N - 1); };
  const_iterator cbegin() { return const_iterator(array_); };
  const_iterator cend() { return const_iterator(array_ + N - 1); };

  bool empty() const { return N == 0; };
  size_type size() const { return N; };
  size_type max_size() const { return N; };

  void swap(array &other);
  void fill(const_reference value);

 private:
  T array_[N];
};
}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_ARRAY_TPP_
