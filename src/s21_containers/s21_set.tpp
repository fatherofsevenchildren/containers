#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_SET_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_SET_TPP_
#include "s21_BinaryTree.hpp"
namespace s21 {

template <typename T>
class set {
 public:
  using key_type = T;
  using value_type = key_type;
  using reference = T&;
  using const_reference = const T&;
  using iterator = typename BinaryTree<T, T>::BinaryTreeConstIterator;
  using const_iterator = iterator;
  using size_type = std::size_t;
  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& other);
  set(set&& other);
  ~set() = default;
  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  std::pair<iterator, bool> insert(const_reference value);
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);
  iterator find(const_reference key);
  bool contains(const_reference key);
  template <typename... Args>
  std::pair<iterator, bool> emplace(Args&&... args);
  set& operator=(set&& other);
  set& operator=(const set& other);

 private:
  BinaryTree<value_type, value_type> tree;
};

}  // namespace s21
#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_SET_TPP_