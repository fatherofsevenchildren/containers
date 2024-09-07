#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_TPP_
#include <algorithm>
#include <iostream>

#include "s21_list.hpp"
namespace s21 {
template <typename T>
class queue : private list<T> {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();

  queue<value_type> operator=(queue &&q);
  queue<value_type> operator=(const queue &q);

  const_reference front();
  const_reference back();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(queue &other);
  template <typename... Args>
  void insert_many_back(Args &&...args);
};
}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_TPP_
