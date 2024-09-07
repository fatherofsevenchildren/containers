#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MAP_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MAP_HPP_
#include "s21_map.tpp"
namespace s21 {

template <typename Key, typename T>
map<Key, T>::map() {}

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const& items) {
  tree = BinaryTree<Key, value_type>(items);
}

template <typename Key, typename T>
map<Key, T>::map(const map& other) {
  tree = other.tree;
}

template <typename Key, typename T>
map<Key, T>::map(map&& other) {
  tree = std::move(other.tree);
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  return iterator(tree.begin());
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
  return iterator(tree.end());
}

template <typename Key, typename T>
bool map<Key, T>::empty() {
  return tree.empty();
}

template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::size() {
  return tree.size();
}

template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::max_size() {
  return tree.max_size();
}

template <typename Key, typename T>
void map<Key, T>::clear() {
  tree.clear();
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  return tree.insert(value);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  std::pair<Key, T> value = std::make_pair(key, obj);
  return tree.insert(value);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  std::pair<Key, T> value = std::make_pair(key, obj);
  std::pair<iterator, bool> result = insert(value);
  if (result.second == false) at(key) = obj;
  return result;
}

template <typename Key, typename T>
void map<Key, T>::erase(iterator pos) {
  tree.erase(*pos);
}

template <typename Key, typename T>
void map<Key, T>::swap(map& other) {
  std::swap(tree, other.tree);
}

template <typename Key, typename T>
void map<Key, T>::merge(map& other) {
  tree.merge(other.tree);
}

template <typename Key, typename T>
bool map<Key, T>::contains(const_reference key) {
  return tree.contains(key);
}

template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  return (*tree.at(key)).second;
}

template <typename Key, typename T>
template <typename... Args>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::emplace(
    Args&&... args) {
  return tree.emplace(std::forward<Args>(args)...);
}

template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  return at(key);
}

template <typename Key, typename T>
typename map<Key, T>::map& map<Key, T>::operator=(const map& other) {
  if (this != &other) {
    clear();
    new (this) map(other);
  }
  return *this;
}

template <typename Key, typename T>
typename map<Key, T>::map& map<Key, T>::operator=(map&& other) {
  clear();
  new (this) map(std::move(other));
  return *this;
}

}  // namespace s21
#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MAP_HPP_