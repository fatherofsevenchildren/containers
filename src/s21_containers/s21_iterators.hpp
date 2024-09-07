#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_ITERATORS_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_ITERATORS_HPP_
namespace s21 {

template <typename Key, typename value_type>
BinaryTree<Key, value_type>::BinaryTreeIterator::BinaryTreeIterator(Node *node,
                                                                    Node *root)
    : node_(node), root_(root) {}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::BinaryTreeIterator &
BinaryTree<Key, value_type>::BinaryTreeIterator::operator++() {
  if (node_->right != nullptr) {
    node_ = BinaryTree::findMinValue(node_->right);
  } else {
    Node *parent = node_->parent;
    while (parent != nullptr && node_ == parent->right) {
      node_ = parent;
      parent = parent->parent;
    }
    node_ = parent;
  }
  return *this;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::BinaryTreeIterator &
BinaryTree<Key, value_type>::BinaryTreeIterator::operator--() {
  if (node_ == nullptr && root_ != nullptr) {
    node_ = BinaryTree::findMaxValue(root_);
  } else {
    if (node_->left != nullptr) {
      node_ = BinaryTree::findMaxValue(node_->left);
    } else {
      Node *parent = node_->parent;
      while (parent != nullptr && node_ == parent->left) {
        node_ = parent;
        parent = parent->parent;
      }
      node_ = parent;
    }
  }
  return *this;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::BinaryTreeIterator
BinaryTree<Key, value_type>::BinaryTreeIterator::operator++(int) {
  iterator it(*this);
  ++(*this);
  return it;
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::BinaryTreeIterator
BinaryTree<Key, value_type>::BinaryTreeIterator::operator--(int) {
  iterator it(*this);
  --(*this);
  return it;
}

template <typename Key, typename value_type>
bool BinaryTree<Key, value_type>::BinaryTreeIterator::operator==(
    const BinaryTreeIterator &other) const {
  return node_ == other.node_;
}

template <typename Key, typename value_type>
bool BinaryTree<Key, value_type>::BinaryTreeIterator::operator!=(
    const BinaryTreeIterator &other) const {
  return !(*this == other);
}

template <typename Key, typename value_type>
typename BinaryTree<Key, value_type>::reference
BinaryTree<Key, value_type>::BinaryTreeIterator::operator*() const {
  if (node_ != nullptr) {
    return node_->data;
  } else {
    static value_type default_value{};
    return default_value;
  }
}

}  // namespace s21
#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_ITERATORS_HPP_