#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_TPP_
#include <algorithm>
#include <iostream>

#include "s21_list.hpp"
namespace s21 {
template <typename T>
class stack : private list<T> {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &q);
  stack(stack &&q);
  ~stack();

  stack<value_type> operator=(stack &&q);
  stack<value_type> operator=(const stack &q);

  const_reference top();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(stack &other);
  template <typename... Args>
  void insert_many_front(Args &&...args);
};
}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_TPP_
