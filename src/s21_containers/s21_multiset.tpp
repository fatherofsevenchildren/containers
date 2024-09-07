#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MULTISET_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MULTISET_TPP_
#include "s21_BinaryTree.hpp"
namespace s21 {

template <typename T>
class multiset {
 public:
  using key_type = T;
  using value_type = key_type;
  using reference = T&;
  using const_reference = const T&;
  using iterator = typename BinaryTree<T, T>::BinaryTreeConstIterator;
  using const_iterator = iterator;
  using size_type = std::size_t;
  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& other);
  multiset(multiset&& other);
  ~multiset() = default;
  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  iterator insert(const_reference value);
  void erase(iterator pos);
  void swap(multiset& other);
  void merge(multiset& other);
  size_type count(const_reference key);
  iterator find(const_reference key);
  bool contains(const_reference key);
  std::pair<iterator, iterator> equal_range(const_reference key);
  iterator lower_bound(const_reference key);
  iterator upper_bound(const_reference key);
  template <typename... Args>
  std::pair<iterator, bool> emplace(Args&&... args);
  multiset& operator=(multiset&& other);
  multiset& operator=(const multiset& other);

 private:
  BinaryTree<value_type, value_type> tree = NUNIQUE;
};

}  // namespace s21
#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_MULTISET_TPP_