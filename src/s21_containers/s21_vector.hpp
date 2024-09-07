#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_VECTOR_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_VECTOR_HPP_

#include "s21_vector.tpp"
namespace s21 {

template <typename T>
void vector<T>::zero_vector() {
  size_ = 0;
  capacity_ = 0;
  vector_ = nullptr;
}

template <typename T>
vector<T>::vector() : size_(0), capacity_(0), vector_(nullptr) {}

template <typename T>
vector<T>::vector(size_type n) : size_(n), capacity_(n) {
  vector_ = new T[capacity_]();
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : size_(items.size()),
      capacity_(items.size()),
      vector_(new T[items.size()]) {
  std::copy(items.begin(), items.end(), vector_);
}

template <typename T>
vector<T>::vector(vector &v)
    : size_(v.size_), capacity_(v.size_), vector_(new value_type[v.size_]) {
  std::copy(v.vector_, v.vector_ + v.size_, vector_);
}

template <typename T>
vector<T>::vector(vector &&v)
    : size_(v.size_), capacity_(v.size_), vector_(v.vector_) {
  v.zero_vector();
}

template <typename T>
vector<T>::~vector() {
  if (vector_ != nullptr) delete[] vector_;
  zero_vector();
}

template <typename T>
vector<T> vector<T>::operator=(const vector &v) {
  vector<T> res(v);
  return res;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&v) {
  swap(v);
  if (v.vector_ != nullptr) delete[] v.vector_;
  v.zero_vector();
  return *this;
}

template <typename T>
void vector<T>::swap(vector<T> &other) {
  std::swap(vector_, other.vector_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
typename vector<T>::const_reference vector<T>::at(size_type pos) const {
  if (pos > size_) {
    throw std::out_of_range("incorrect");
  }
  return vector_[pos];
}

template <typename T>
void vector<T>::realloc(size_type new_size) {
  T *carrunt_vector = new T[new_size]();
  std::copy(vector_, vector_ + size_, carrunt_vector);
  delete[] vector_;
  vector_ = carrunt_vector;
  capacity_ = new_size;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size <= capacity_) {
    return;
  }
  if (size > max_size()) {
    throw std::out_of_range("ReserveError: Too large size for a new capacity");
  }
  realloc(size);
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ == capacity_) {
    return;
  }
  realloc(size_);
}

template <typename T>
void vector<T>::clear() {
  std::fill(vector_, vector_ + size_, 0);
  size_ = 0;
}

template <typename T>
VectorIterator<T> vector<T>::insert(iterator pos, const_reference value) {
  vector<T> tmp(size_ == capacity_ ? size_ * 2 : capacity_);
  tmp.size_ = this->size_ + 1;
  size_t int_pos = pos.base() - vector_, j = 0;
  for (size_t i = 0; i < size_ + 1; i++) {
    if (i == int_pos) {
      tmp[i] = value;
    } else {
      tmp[i] = vector_[j++];
    }
  }
  *this = std::move(tmp);
  return iterator(vector_ + int_pos);
}

template <typename T>
void vector<T>::erase(iterator pos) {
  size_t int_pos = pos.base() - vector_, j = 0;
  for (size_t i = 0; i < size_; i++) {
    if (i != int_pos) {
      vector_[j++] = vector_[i];
    }
  }
  size_--;
  return;
}

template <typename T>
void vector<T>::push_back(const T &value) {
  if (max_size() <= size_) {
    throw std::out_of_range("incorrect");
  }
  if (size_ == capacity_) {
    vector<T> tmp(size_ * 2);
    tmp.size_ = size_ + 1;
    std::copy(vector_, vector_ + size_, tmp.vector_);
    tmp.vector_[size_] = value;
    *this = std::move(tmp);
  } else {
    vector_[size_++] = value;
  }
  return;
}

template <typename T>
void vector<T>::pop_back() {
  if (size_ > 0) {
    size_--;
  }
  return;
}

template <typename T>
template <typename... Args>
VectorIterator<T> vector<T>::insert_many(iterator pos, Args &&...args) {
  vector<T> tmp{args...};
  size_t int_pos = pos.base() - vector_ + 1;
  for (size_t i = 0; i < tmp.size(); i++) {
    insert(iterator(begin().base() + int_pos + i), tmp[i]);
  }
  return pos;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  insert_many(--(end()), args...);
}
}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_VECTOR_HPP_
