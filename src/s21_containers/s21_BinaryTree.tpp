#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_BINARYTREE_BINARY_TREE_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_BINARYTREE_BINARY_TREE_TPP_

namespace s21 {

#define UNIQUE 1
#define NUNIQUE 2
template <typename Key, typename T>
class BinaryTree {
 public:
  class Node;
  class BinaryTreeIterator;
  class BinaryTreeConstIterator;
  using key_type = Key;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = BinaryTree<Key, T>::BinaryTreeIterator;
  using const_iterator = BinaryTree<Key, T>::BinaryTreeConstIterator;
  using size_type = std::size_t;
  BinaryTree();
  BinaryTree(const value_type &type);
  BinaryTree(std::initializer_list<value_type> const &items);
  BinaryTree(const BinaryTree &other);
  BinaryTree(BinaryTree &&other);
  ~BinaryTree();
  std::pair<iterator, bool> insert(const_reference data, Node *&node,
                                   Node *parent = nullptr);
  std::pair<iterator, bool> insert(const_reference data);
  void erase(const_reference data, Node *node);
  void erase(const_reference data);
  void removeNodeWithOneChild(Node *&node, Node *branch);
  void removeNodeWithTwoChildren(Node *node);
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void clear(Node *node);
  void clear();
  iterator find(const_reference key);
  iterator at(const key_type &key);
  bool contains(const_reference key);
  void merge(BinaryTree &other);
  size_type count(const_reference key);
  iterator lower_bound(const_reference key);
  iterator upper_bound(const_reference key);
  template <typename... Args>
  std::pair<iterator, bool> emplace(Args &&...args);
  static Node *findMinValue(Node *node);
  static Node *findMaxValue(Node *node);
  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;
  BinaryTree &operator=(const BinaryTree &other);
  BinaryTree &operator=(BinaryTree &&other);

 private:
  Node *root{nullptr};
  int type{UNIQUE};
};

template <typename Key, typename value_type>
class BinaryTree<Key, value_type>::Node {
 public:
  explicit Node(const value_type &d = value_type{}, Node *l = nullptr,
                Node *r = nullptr, Node *p = nullptr);
  value_type data;
  Node *left;
  Node *right;
  Node *parent;
};

template <typename Key, typename value_type>
class BinaryTree<Key, value_type>::BinaryTreeIterator {
 public:
  BinaryTreeIterator() = default;
  explicit BinaryTreeIterator(Node *node, Node *root = nullptr);
  BinaryTreeIterator &operator++();
  BinaryTreeIterator &operator--();
  BinaryTreeIterator operator++(int);
  BinaryTreeIterator operator--(int);
  bool operator==(const BinaryTreeIterator &other) const;
  bool operator!=(const BinaryTreeIterator &other) const;
  reference operator*() const;

 private:
  Node *node_{nullptr};
  Node *root_{nullptr};
};

template <typename Key, typename value_type>
class BinaryTree<Key, value_type>::BinaryTreeConstIterator
    : public BinaryTreeIterator {
 public:
  BinaryTreeConstIterator() = default;
  explicit BinaryTreeConstIterator(Node *node, Node *root = nullptr);
  BinaryTreeConstIterator(const BinaryTreeIterator &it);
  BinaryTreeConstIterator &operator++();
  BinaryTreeConstIterator &operator--();
  BinaryTreeConstIterator operator++(int);
  BinaryTreeConstIterator operator--(int);
  bool operator==(const BinaryTreeConstIterator &other) const;
  bool operator!=(const BinaryTreeConstIterator &other) const;
  const_reference operator*() const;

 private:
  BinaryTreeIterator it;
};

}  // namespace s21
#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_BINARYTREE_BINARY_TREE_TPP_