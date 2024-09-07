#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_HPP_

#include "s21_stack.tpp"

namespace s21 {

template <typename T>
stack<T>::stack() {
  list<T>();
}

template <typename T>
stack<T>::stack(const std::initializer_list<value_type> &items) {
  auto it = items.begin();
  for (size_type i = 0; i < items.size(); i++) {
    push(*it++);
  }
}

template <typename T>
stack<T>::stack(const stack<T> &q) : list<T>(q) {}

template <typename T>
stack<T>::stack(stack<T> &&q) {
  list<T>::redirect(q);
}

template <typename T>
stack<T>::~stack() {
  if (list<T>::end_ != nullptr) delete list<T>::end_;
  list<T>::end_ = nullptr;
  list<T>::clear();
}

template <typename T>
stack<T> stack<T>::operator=(stack<T> &&q) {
  list<T>::clear();
  list<T>::redirect(q);
  return *this;
}

template <typename T>
stack<T> stack<T>::operator=(const stack<T> &q) {
  list<T>::clear();
  list<T>::copyList(q);
  return *this;
}

template <typename T>
const T &stack<T>::top() {
  return list<T>::front();
}

template <typename T>
bool stack<T>::empty() {
  return list<T>::empty();
}

template <typename T>
size_t stack<T>::size() {
  return list<T>::size();
}
template <typename T>
void stack<T>::push(const_reference value) {
  list<T>::push_front(value);
}

template <typename T>
void stack<T>::pop() {
  list<T>::pop_front();
}

template <typename T>
void stack<T>::swap(stack<T> &other) {
  list<T>::swap(other);
}
template <typename T>
template <typename... Args>
void stack<T>::insert_many_front(Args &&...args) {
  list<T>::insert_many_front(args...);
}
}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_HPP_