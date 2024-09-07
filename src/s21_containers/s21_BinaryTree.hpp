#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_BINARYTREE_BINARY_TREE_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_BINARYTREE_BINARY_TREE_HPP_
#include "s21_BinaryTree.tpp"
#include "s21_const_iterators.hpp"
#include "s21_iterators.hpp"
namespace s21 {

template <typename Key, typename value_type>
BinaryTree<Key, value_type>::Node::Node(const value_type &d, Node *l, Node *r,
                                        Node *p)
    : data(d), left(l), right(r), parent(p) {}

template <typename Key, typename value_type>
BinaryTree<Key, value_type>::BinaryTree() : root(nullptr) {}

template <typename Key, typename value_type>
BinaryTree<Key, value_type>::BinaryTree(const value_type &type)
    : root(nullptr), type(type) {}

template <typename Key, typename value_type>
BinaryTree<Key, value_type>::BinaryTree(
    std::initializer_list<value_type> const &items) {
  for (auto &i : items) {
    insert(i);
  }
}

template <typename Key, typename value_type>
BinaryTree<Key, value_type>::BinaryTree(const BinaryTree &other)
    : type(other.type) {
  for (auto it = other.cbegin(); it != other.cend(); ++it) {
    insert(*it);
  }
}

template <typename Key, typename value_type>
BinaryTree<Key, value_type>::BinaryTree(BinaryTree &&other)
    : root(other.root), type(other.type) {
  other.root = nullptr;
}

template <typename Key, typename value_type>
BinaryTree<Key, value_type>::~BinaryTree() {
  clear(root);
}

template <typename Key, typename value_type>
std::pair<typename BinaryTree<Key, value_type>::iterator, bool>
BinaryTree<Key, value_type>::insert(const_reference data, Node *&node,
                                    Node *parent) {
  if (node == nullptr) {
    node = new Node(data, nullptr, nullptr, parent);
    return {iterator(node), true};
  } else {
    if (data < node->data) {
      return insert(data, node->left, node);
    } else if (data > node->data) {
      return insert(data, node->right, node);
    } else {
      if (type == UNIQUE) {
        return {iterator(node), false};
      } else {
        if (node->left == nullptr) {
          return insert(data, node->left, node);
        } else {
          Node *newNode = new Node(data, node->left, nullptr, node);
          node->left->parent = newNode;
          node->left = newNode;
          return {iterator(newNode), true};
        }
      }
    }
  }
}

template <typename Key, typename value_type>
std::pair<typename BinaryTree<Key, value_type>::iterator, bool>
BinaryTree<Key, value_type>::insert(const_reference data) {
  return insert(data, root, nullptr);
}

template <typename Key, typename value_type>
void BinaryTree<Key, value_type>::erase(const_reference data, Node *node) {
  if (node == nullptr) return;
  if (data < node->data) {
    erase(data, node->left);
  } else if (data > node->data) {
    erase(data, node->right);
  } else if (data == node->data) {
    if (node->left == nullptr && node->right == nullptr) {
      Node *parent = node->parent;
      if (parent != nullptr) {
        if (data > parent->data) {
          parent->right = nullptr;
        } else if (data < parent->data) {
          parent->left = nullptr;
        }
      } else {
        root = nullptr;
      }
      delete node;
    } else if (node->left == nullptr) {
      removeNodeWithOneChild(node, node->right);
    } else if (node->right == nullptr) {
      removeNodeWithOneChild(node, node->left);
    } else {
      removeNodeWithTwoChildren(node);
    }
  }
}

template <typename Key, typename value_type>
void BinaryTree<Key, value_type>::removeNodeWithOneChild(Node *&node,
                                                         Node *branch) {
  Node *parent = node->parent;
  Node *temp = node;
  if (parent != nullptr) {
    if (parent->left == node) {
      parent->left = branch;
    } else {
      parent->right = branch;
    }
  } else {
    root = branch;
  }
  node = branch;
  node->parent = parent;
  delete temp;
}

template <typename Key, typename value_type>
void BinaryTree<Key, value_type>::removeNodeWithTwoChildren(Node *node) {
  Node *temp = findMinValue(node->right);
  if (temp->right != nullptr) {
    temp->right->parent = temp->parent;
  }
  if (temp->parent->left == temp) {
    temp->parent->left = temp->right;
  } else {
    temp->parent->right = temp->right;
  }
  temp->parent = node->parent;
  if (node->parent != nullptr) {
    if (node->parent->left == node) {
      node->parent->left = temp;
    } else {
      node->parent->right = temp;
    }
  }
  temp->left = node->left;
  temp->right = node->right;
  node->left->parent = temp;
  if (node->right != nullptr) {
    node->right->parent = temp;
  }
  if (node == root) {
    root = temp;
  }
  delete node;
}

template <typename Key, typename value_type>
void BinaryTree<Key, value_type>::erase(const_reference data) {
  erase(data, root);
}

template <typename Key, typename value_type>
bool BinaryTree<Key, value_type>::empty() const {
  return root == nullptr;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::size_type
BinaryTree<Key, value_type>::size() const {
  size_type size = 0;
  for (auto it = cbegin(); it != cend(); ++it) {
    ++size;
  }
  return size;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::size_type
BinaryTree<Key, value_type>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 3;
}

template <typename Key, typename value_type>
void BinaryTree<Key, value_type>::clear(Node *node) {
  if (node != nullptr) {
    clear(node->left);
    clear(node->right);
    delete node;
  }
}

template <typename Key, typename value_type>
void BinaryTree<Key, value_type>::clear() {
  clear(root);
  root = nullptr;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::iterator
BinaryTree<Key, value_type>::find(const_reference key) {
  Node *node = root;
  while (node != nullptr) {
    if (key < node->data) {
      node = node->left;
    } else if (key > node->data) {
      node = node->right;
    } else if (key == node->data) {
      while (node->left != nullptr && node->left->data == key) {
        node = node->left;
      }
      return iterator(node);
    }
  }
  return iterator(end());
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::iterator BinaryTree<Key, value_type>::at(
    const key_type &key) {
  for (Node *node = root; node != nullptr;) {
    if (key < node->data.first) {
      node = node->left;
    } else if (key > node->data.first) {
      node = node->right;
    } else {
      return iterator(node);
    }
  }
  throw std::out_of_range("Found no mapped value stored by given key");
}

template <typename Key, typename value_type>
bool BinaryTree<Key, value_type>::contains(const_reference key) {
  Node *node = root;
  while (node != nullptr) {
    if (key < node->data) {
      node = node->left;
    } else if (key > node->data) {
      node = node->right;
    } else if (key == node->data) {
      return true;
    }
  }
  return false;
}

template <typename Key, typename value_type>
void BinaryTree<Key, value_type>::merge(BinaryTree &other) {
  if (type == UNIQUE) {
    for (auto it = other.begin(); it != other.end();) {
      if (!contains(*it)) {
        insert(*it);
        other.erase(*(it++));
      } else {
        ++it;
      }
    }
  } else {
    for (auto it = other.begin(); it != other.end(); ++it) {
      insert(*it);
    }
    other.clear();
  }
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::size_type
BinaryTree<Key, value_type>::count(const_reference key) {
  size_type n = 0;
  for (iterator it = find(key); it != end() && *it == key; ++it, ++n) {
  }
  return n;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::iterator
BinaryTree<Key, value_type>::lower_bound(const_reference key) {
  Node *lowerBound = nullptr;
  for (Node *current = root; current;) {
    if (key < current->data) {
      lowerBound = current;
      current = current->left;
    } else if (key > current->data) {
      current = current->right;
    } else {
      return iterator(current);
    }
  }
  return iterator(lowerBound);
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::iterator
BinaryTree<Key, value_type>::upper_bound(const_reference key) {
  Node *upperBound = nullptr;
  for (Node *current = root; current;) {
    if (key < current->data) {
      upperBound = current;
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return iterator(upperBound);
}

template <typename Key, typename value_type>
template <typename... Args>
std::pair<typename BinaryTree<Key, value_type>::iterator, bool>
BinaryTree<Key, value_type>::emplace(Args &&...args) {
  std::pair<iterator, bool> it;
  for (auto &&item : {std::forward<Args>(args)...}) {
    it = insert(item);
  }
  return it;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::Node *
BinaryTree<Key, value_type>::findMinValue(Node *node) {
  Node *temp = node;
  while (temp->left != nullptr) {
    temp = temp->left;
  }
  return temp;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::Node *
BinaryTree<Key, value_type>::findMaxValue(Node *node) {
  Node *temp = node;
  while (temp->right != nullptr) {
    temp = temp->right;
  }
  return temp;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::iterator
BinaryTree<Key, value_type>::begin() {
  if (!empty()) {
    return iterator(findMinValue(root), root);
  } else {
    return iterator(nullptr);
  }
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::iterator
BinaryTree<Key, value_type>::end() {
  return iterator(nullptr, root);
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::const_iterator
BinaryTree<Key, value_type>::cbegin() const {
  if (!empty()) {
    return const_iterator(findMinValue(root), root);
  } else {
    return const_iterator(nullptr);
  }
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::const_iterator
BinaryTree<Key, value_type>::cend() const {
  return const_iterator(nullptr, root);
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::BinaryTree &
BinaryTree<Key, value_type>::operator=(const BinaryTree &other) {
  if (this != &other) {
    clear();
    new (this) BinaryTree(other);
  }
  return *this;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::BinaryTree &
BinaryTree<Key, value_type>::operator=(BinaryTree &&other) {
  if (this != &other) {
    clear();
    new (this) BinaryTree(std::move(other));
  }
  return *this;
}

}  // namespace s21
#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_BINARYTREE_BINARY_TREE_HPP_