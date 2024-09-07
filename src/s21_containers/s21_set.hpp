#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_SET_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_SET_HPP_
#include "s21_set.tpp"
namespace s21 {

template <typename value_type>
set<value_type>::set() {}

template <typename value_type>
set<value_type>::set(std::initializer_list<value_type> const& items) {
  tree = BinaryTree<value_type, value_type>(items);
}

template <typename value_type>
set<value_type>::set(const set& other) {
  tree = other.tree;
}

template <typename value_type>
set<value_type>::set(set&& other) {
  tree = std::move(other.tree);
}

template <typename value_type>
typename set<value_type>::iterator set<value_type>::begin() {
  return iterator(tree.cbegin());
}

template <typename value_type>
typename set<value_type>::iterator set<value_type>::end() {
  return iterator(tree.cend());
}

template <typename value_type>
bool set<value_type>::empty() {
  return tree.empty();
}

template <typename value_type>
typename set<value_type>::size_type set<value_type>::size() {
  return tree.size();
}

template <typename value_type>
typename set<value_type>::size_type set<value_type>::max_size() {
  return tree.max_size();
}

template <typename value_type>
void set<value_type>::clear() {
  tree.clear();
}

template <typename value_type>
std::pair<typename set<value_type>::iterator, bool> set<value_type>::insert(
    const_reference value) {
  return tree.insert(value);
}

template <typename value_type>
void set<value_type>::erase(iterator pos) {
  tree.erase(*pos);
}

template <typename value_type>
void set<value_type>::swap(set& other) {
  std::swap(tree, other.tree);
}

template <typename value_type>
void set<value_type>::merge(set& other) {
  tree.merge(other.tree);
}

template <typename value_type>
typename set<value_type>::iterator set<value_type>::find(const_reference key) {
  return tree.find(key);
}

template <typename value_type>
bool set<value_type>::contains(const_reference key) {
  return tree.contains(key);
}

template <typename value_type>
template <typename... Args>
std::pair<typename set<value_type>::iterator, bool> set<value_type>::emplace(
    Args&&... args) {
  return tree.emplace(std::forward<Args>(args)...);
}

template <typename value_type>
typename set<value_type>::set& set<value_type>::operator=(set&& other) {
  clear();
  new (this) set(std::move(other));
  return *this;
}

template <typename value_type>
typename set<value_type>::set& set<value_type>::operator=(const set& other) {
  if (this != &other) {
    clear();
    new (this) set(other);
  }
  return *this;
}

}  // namespace s21
#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_SET_HPP_
