#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MULTISET_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MULTISET_HPP_
#include "s21_multiset.tpp"
namespace s21 {

template <typename value_type>
multiset<value_type>::multiset() {}

template <typename value_type>
multiset<value_type>::multiset(std::initializer_list<value_type> const& items) {
  for (auto& i : items) {
    insert(i);
  }
}

template <typename value_type>
multiset<value_type>::multiset(const multiset& other) {
  tree = other.tree;
}

template <typename value_type>
multiset<value_type>::multiset(multiset&& other) {
  tree = std::move(other.tree);
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::begin() {
  return iterator(tree.begin());
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::end() {
  return iterator(tree.end());
}

template <typename value_type>
bool multiset<value_type>::empty() {
  return tree.empty();
}

template <typename value_type>
typename multiset<value_type>::size_type multiset<value_type>::size() {
  return tree.size();
}

template <typename value_type>
typename multiset<value_type>::size_type multiset<value_type>::max_size() {
  return tree.max_size();
}

template <typename value_type>
void multiset<value_type>::clear() {
  tree.clear();
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::insert(
    const_reference value) {
  return iterator(tree.insert(value).first);
}

template <typename value_type>
void multiset<value_type>::erase(iterator pos) {
  tree.erase(*pos);
}

template <typename value_type>
void multiset<value_type>::swap(multiset& other) {
  std::swap(tree, other.tree);
}

template <typename value_type>
void multiset<value_type>::merge(multiset& other) {
  tree.merge(other.tree);
}

template <typename value_type>
typename multiset<value_type>::size_type multiset<value_type>::count(
    const_reference key) {
  return tree.count(key);
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::find(
    const_reference key) {
  return tree.find(key);
}

template <typename value_type>
bool multiset<value_type>::contains(const_reference key) {
  return tree.contains(key);
}

template <typename value_type>
std::pair<typename multiset<value_type>::iterator,
          typename multiset<value_type>::iterator>
multiset<value_type>::equal_range(const_reference key) {
  return {lower_bound(key), upper_bound(key)};
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::lower_bound(
    const_reference key) {
  return iterator(tree.lower_bound(key));
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::upper_bound(
    const_reference key) {
  return iterator(tree.upper_bound(key));
}

template <typename value_type>
template <typename... Args>
std::pair<typename multiset<value_type>::iterator, bool>
multiset<value_type>::emplace(Args&&... args) {
  return tree.emplace(std::forward<Args>(args)...);
}

template <typename value_type>
typename multiset<value_type>::multiset& multiset<value_type>::operator=(
    multiset&& other) {
  clear();
  new (this) multiset(std::move(other));
  return *this;
}

template <typename value_type>
typename multiset<value_type>::multiset& multiset<value_type>::operator=(
    const multiset& other) {
  if (this != &other) {
    clear();
    new (this) multiset(other);
  }
  return *this;
}

}  // namespace s21
#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MULTISET_HPP_