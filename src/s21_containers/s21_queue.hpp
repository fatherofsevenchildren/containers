#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_HPP_

#include "s21_queue.tpp"

namespace s21 {

template <typename T>
queue<T>::queue() {
  list<T>();
}

template <typename T>
queue<T>::queue(const std::initializer_list<value_type> &items) {
  auto it = items.begin();
  for (size_type i = 0; i < items.size(); i++) {
    list<T>::push_back(*it++);
  }
}

template <typename T>
queue<T>::queue(const queue<T> &q) : list<T>(q) {}

template <typename T>
queue<T>::queue(queue<T> &&q) {
  list<T>::redirect(q);
}

template <typename T>
queue<T>::~queue() {
  if (list<T>::end_ != nullptr) delete list<T>::end_;
  list<T>::end_ = nullptr;
  list<T>::clear();
}

template <typename T>
queue<T> queue<T>::operator=(queue<T> &&q) {
  list<T>::clear();
  list<T>::redirect(q);
  return *this;
}

template <typename T>
queue<T> queue<T>::operator=(const queue<T> &q) {
  list<T>::clear();
  list<T>::copyList(q);
  return *this;
}

template <typename T>
const T &queue<T>::front() {
  return list<T>::front();
}

template <typename T>
const T &queue<T>::back() {
  return list<T>::back();
}

template <typename T>
bool queue<T>::empty() {
  return list<T>::empty();
}

template <typename T>
size_t queue<T>::size() {
  return list<T>::size();
}
template <typename T>
void queue<T>::push(const_reference value) {
  list<T>::push_back(value);
}

template <typename T>
void queue<T>::pop() {
  list<T>::pop_front();
}

template <typename T>
void queue<T>::swap(queue<T> &other) {
  list<T>::swap(other);
}

template <typename T>
template <typename... Args>
void queue<T>::insert_many_back(Args &&...args) {
  list<T>::insert_many_back(args...);
}

}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_HPP_
