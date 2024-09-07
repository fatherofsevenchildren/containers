#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_ARRAY_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_ARRAY_HPP_

#include "s21_array.tpp"

namespace s21 {
template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  std::copy(items.begin(), items.end(), array_);
}

template <typename T, size_t N>
array<T, N>::array(array &v) {
  std::copy(v.array_, v.array_ + N, array_);
}

template <typename T, size_t N>
array<T, N>::array(array &&v) {
  fill(0);
  swap(v);
}

template <typename T, size_t N>
array<T, N> array<T, N>::operator=(const array &v) {
  array<T, N> res(v);
  return res;
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&v) {
  array_ = v.array_;
  v.fill(0);
  return *this;
}

template <typename T, size_t N>
void array<T, N>::swap(array<T, N> &other) {
  std::swap(array_, other.array_);
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_t i = 0; i < N; i++) {
    array_[i] = value;
  }
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type pos) const {
  if (pos > N) {
    throw std::out_of_range("incorrect");
  }
  return array_[pos];
}
}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_ARRAY_HPP_