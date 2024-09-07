#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MAP_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MAP_TPP_
#include "s21_BinaryTree.hpp"
namespace s21 {
template <typename Key, typename T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename BinaryTree<Key, value_type>::BinaryTreeIterator;
  using const_iterator = iterator;
  using size_type = std::size_t;
  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& other);
  map(map&& other);
  ~map() = default;
  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);
  template <typename... Args>
  std::pair<iterator, bool> emplace(Args&&... args);
  bool contains(const_reference key);
  T& at(const Key& key);
  map& operator=(const map& other);
  map& operator=(map&& other);
  T& operator[](const Key& key);

 private:
  BinaryTree<Key, value_type> tree;
};

}  // namespace s21
#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MAP_TPP_