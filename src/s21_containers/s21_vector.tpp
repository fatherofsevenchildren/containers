#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_VECTOR_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_VECTOR_TPP_

#include <algorithm>
#include <iostream>

#include "s21_vector_iterators.hpp"
namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using iterator = VectorIterator<T>;
  using const_iterator = VectorConstIterator<T>;

 public:
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(vector &v);
  vector(vector &&v);
  vector &operator=(vector &&v);
  vector operator=(const vector &v);

  ~vector();
  reference operator[](size_type pos) { return vector_[pos]; };
  const_reference at(size_type pos) const;
  const_reference back() { return vector_[size_ - 1]; };
  const_reference front() { return vector_[0]; };
  T *data() { return vector_; };

  iterator begin() { return iterator(vector_); };
  iterator end() { return iterator(vector_ + size_); };
  const_iterator cbegin() { return const_iterator(vector_); };
  const_iterator cend() { return const_iterator(vector_ + size_); };

  bool empty() const { return vector_ == nullptr; };
  size_type size() const { return size_; };
  size_type max_size() const {
    return std::numeric_limits<std::size_t>::max() / (sizeof(value_type));
  };
  void reserve(size_type size);
  size_type capacity() const { return capacity_; };
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  template <typename... Args>
  iterator insert_many(iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  size_type size_;
  size_type capacity_;
  T *vector_;
  void zero_vector();
  void realloc(size_type new_size);
};
}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_VECTOR_TPP_

// int x = 5;
// int &y = x;
// y = 3; -- x = 3;