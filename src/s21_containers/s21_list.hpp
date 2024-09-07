#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_LIST_HPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_LIST_HPP_

#include "s21_list.tpp"

namespace s21 {

template <typename T>
list<T>::list() : size_(0), head_(nullptr), last_(nullptr), end_(nullptr) {
  end_ = new Node(0, end_, end_);
}

template <typename T>
list<T>::list(size_type n)
    : size_(0), head_(nullptr), last_(nullptr), end_(nullptr) {
  end_ = new Node(0, end_, end_);
  for (size_type i = 0; i < n; i++) {
    push_front(0);
  }
  head_->pPrev = end_;
  last_->pNext = end_;
}

template <typename T>
list<T>::list(const list &list)
    : size_(0), head_(nullptr), last_(nullptr), end_(nullptr) {
  end_ = new Node(0, end_, end_);
  this->copyList(list);
}

template <typename T>
list<T>::list(list<T> &&list) noexcept {
  end_ = new Node(0, end_, end_);
  redirect(list);
}

template <typename T>
list<T>::list(const std::initializer_list<value_type> &items)
    : size_(0), head_(nullptr), last_(nullptr) {
  end_ = new Node(0, end_, end_);
  auto it = items.begin();
  for (size_type i = 0; i < items.size(); i++) push_back(*it++);
  end_->pNext = head_;
  end_->pPrev = last_;
}

template <typename T>
list<T>::~list() {
  clear();
  delete end_;
}

template <typename T>
void list<T>::push_back(value_type data) {
  if (head_ == nullptr) {
    head_ = new Node(data, end_, end_);
    last_ = head_;
  } else {
    last_->pNext = new Node(data, end_, last_);
    last_ = last_->pNext;
  }
  size_++;
}

template <typename T>
void list<T>::push_front(value_type data) {
  if (head_ == nullptr) {
    head_ = new Node(data, end_, end_);
    last_ = head_;
  } else {
    Node *tmp_prev = head_->pPrev;
    head_->pPrev = new Node(data, head_, end_);
    tmp_prev->pNext = head_->pPrev;
    head_ = head_->pPrev;
  }
  size_++;
}

template <typename T>
void list<T>::pop_back() {
  if (size_ == 1) {
    delete head_;
    last_ = nullptr;
    size_--;
  } else if (size_ > 1) {
    Node *tmp_node = last_;
    last_ = last_->pPrev;
    last_->pNext = end_;
    delete tmp_node;
    size_--;
  }
  rootRedirectPop();
}

template <typename T>
void list<T>::pop_front() {
  if (size_ == 1) {
    delete head_;
    last_ = nullptr;
    size_--;
  } else if (size_ > 1) {
    Node *tmp_node = head_;
    head_ = head_->pNext;
    head_->pPrev = end_;
    delete tmp_node;
    size_--;
  }
  rootRedirectPop();
}

template <typename T>
void list<T>::clear() {
  while (size_) pop_front();
}

template <typename T>
bool list<T>::empty() const {
  return size_ == 0;
}

template <typename T>
list<T> &list<T>::operator=(const list<T> &list) {
  this->clear();
  copyList(list);
  return *this;
}

template <typename T>
list<T> &list<T>::operator=(list<T> &&list) noexcept {
  this->clear();
  redirect(list);
  return *this;
}

template <typename T>
void list<T>::copyList(const list<T> &list) {
  size_ = 0;
  head_ = nullptr;
  last_ = nullptr;
  auto it = list.begin();
  for (int i = 0; i < list.size_; i++) {
    push_back(*it);
    ++it;
  }
  rootRedirect();
}

template <typename T>
void list<T>::erase(iterator pos) {
  if (pos.getData() == head_ && size_ > 0)
    pop_front();
  else if (pos.getData() == last_ && size_ > 0)
    pop_back();
  else if (pos.getData() != end_ && size_ > 0) {
    Node *tmp_node = pos.getData();
    Node *tmp_next = tmp_node->pNext;
    Node *tmp_prev = tmp_node->pPrev;
    delete tmp_node;
    tmp_next->pPrev = tmp_prev;
    tmp_prev->pNext = tmp_next;
    size_--;
  }
}

template <typename T>
void list<T>::insert(iterator pos, value_type data) {
  if (pos.getData() == head_) {
    push_front(data);
  } else if (pos.getData() == end_) {
    push_back(data);
  } else {
    Node *tmp_next = pos.getData();
    Node *tmp_prev = tmp_next->pPrev;
    Node *tmp_node = new Node(data, tmp_next, tmp_prev);
    tmp_prev->pNext = tmp_node;
    tmp_next->pPrev = tmp_node;
    size_++;
  }
}

template <typename T>
void list<T>::redirect(list<T> &list) {
  Node *tmp_empty = end_;
  last_ = list.last_;
  head_ = list.head_;
  size_ = list.size_;
  end_ = list.end_;
  list.size_ = 0;
  list.head_ = nullptr;
  list.last_ = nullptr;
  list.end_ = tmp_empty;
}

template <typename T>
void list<T>::swap(list<T> &other) {
  Node *tmp_head = head_;
  Node *tmp_end = last_;
  Node *tmp_empty = end_;
  int tmp_size = size_;
  head_ = other.head_;
  last_ = other.last_;
  size_ = other.size_;
  end_ = other.end_;
  other.head_ = tmp_head;
  other.last_ = tmp_end;
  other.size_ = tmp_size;
  other.end_ = tmp_empty;
}

template <typename T>
void list<T>::reverse() {
  Node *tmp_head = head_;
  head_ = last_;
  last_ = tmp_head;
  end_->pPrev = last_;
  end_->pNext = head_;
  for (Node *c = last_; c != end_; c = c->pPrev) {
    Node *tmp_next = c->pNext;
    c->pNext = c->pPrev;
    c->pPrev = tmp_next;
  }
}

template <typename T>
void list<T>::unique() {
  for (Node *c = head_; c != end_; c = c->pNext) {
    for (Node *n = c->pNext; n != end_; n = n->pNext) {
      while (c->data == n->data && n != end_) {
        Node *tmp_to_del = n;
        Node *tmp_prev = n->pPrev;
        n = n->pNext;
        delete tmp_to_del;
        tmp_prev->pNext = n;
        n->pPrev = tmp_prev;
        size_--;
      }
    }
  }
}

template <typename T>
void list<T>::sort() {
  for (Node *c = head_; c != end_; c = c->pNext) {
    for (Node *n = c->pNext; n != end_; n = n->pNext) {
      if (c->data > n->data) {
        T tmp_data = c->data;
        c->data = n->data;
        n->data = tmp_data;
      }
    }
  }
}

template <typename T>
void list<T>::merge(list<T> &other) {
  if (last_ != other.last_ && head_ != other.head_) {
    last_->pNext = other.head_;
    other.head_->pPrev = last_;
    last_ = other.last_;
    rootRedirect();
    size_ += other.size_;
    other.head_ = nullptr;
    other.last_ = nullptr;
    other.size_ = 0;
    other.rootRedirectPop();
  }
}

template <typename T>
void list<T>::splice(iterator pos, list<T> &other) {
  if (head_ != other.head_ && last_ != other.last_) {
    Node *tmp_prev = pos.getData()->pPrev;
    Node *tmp_node = pos.getData();
    tmp_prev->pNext = other.head_;
    tmp_node->pPrev = other.last_;
    other.head_->pPrev = tmp_prev;
    other.last_->pNext = tmp_node;
    size_ += other.size_;
    other.size_ = 0;
    other.head_ = nullptr;
    other.last_ = nullptr;
    other.rootRedirectPop();
  }
}

template <typename T>
size_t list<T>::max_size() const {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}

template <typename T>
T list<T>::ListIterator::operator*() const {
  return pNode_->data;
}

template <typename T>
T list<T>::ListConstIterator::operator*() const {
  return pNode_->data;
}
template <typename T>
typename list<T>::ListIterator &list<T>::ListIterator::operator++() {
  if (pNode_->pNext != nullptr) {
    if (pNode_ != pNodePrev_->pNext) {
      pNode_ = pNodeNext_;
    } else
      pNode_ = pNode_->pNext;
    pNodeNext_ = pNode_->pNext;
    pNodePrev_ = pNode_->pPrev;
  }
  return *this;
}

template <typename T>
typename list<T>::ListIterator &list<T>::ListIterator::operator--() {
  if (pNode_->pPrev != nullptr) {
    if (pNode_ != pNodeNext_->pPrev) {
      pNode_ = pNodePrev_;
    } else
      pNode_ = pNode_->pPrev;
    pNodeNext_ = pNode_->pNext;
    pNodePrev_ = pNode_->pPrev;
  }
  return *this;
}

template <typename T>
bool list<T>::ListIterator::operator!=(list<T>::ListIterator iter) {
  return pNode_ != iter.pNode_;
}

template <typename T>
bool list<T>::ListIterator::operator==(list<T>::ListIterator iter) {
  return pNode_ == iter.pNode_;
}

template <typename T>
bool list<T>::ListConstIterator::operator==(
    const list<T>::ListConstIterator iter) {
  return pNode_ == iter.pNode_;
}

template <typename T>
bool list<T>::ListConstIterator::operator!=(
    const list<T>::ListConstIterator iter) {
  return pNode_ != iter.pNode_;
}

template <typename T>
typename list<T>::ListConstIterator &list<T>::ListConstIterator::operator++() {
  if (pNode_->pNext != nullptr) {
    if (pNode_ != pNodePrev_->pNext) {
      pNode_ = pNodeNext_;
    } else
      pNode_ = pNode_->pNext;
    pNodeNext_ = pNode_->pNext;
    pNodePrev_ = pNode_->pPrev;
  }
  return *this;
}

template <typename T>
typename list<T>::ListConstIterator &list<T>::ListConstIterator::operator--() {
  if (pNode_->pPrev != nullptr) {
    if (pNode_ != pNodeNext_->pPrev) {
      pNode_ = pNodePrev_;
    } else
      pNode_ = pNode_->pPrev;
    pNodeNext_ = pNode_->pNext;
    pNodePrev_ = pNode_->pPrev;
  }
  return *this;
}

template <typename T>
void list<T>::rootRedirect() {
  if (head_ != nullptr) {
    end_->pNext = head_;
    end_->pPrev = last_;
    head_->pPrev = end_;
    last_->pNext = end_;
  }
}

template <typename T>
void list<T>::rootRedirectPop() {
  if (head_ == nullptr) {
    end_->pPrev = end_;
    end_->pNext = end_;
  }
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args &&...args) {
  list<T> tmp = {args...};
  tmp.head_->pPrev = end_;
  tmp.last_->pNext = head_;
  head_->pPrev = tmp.last_;
  end_->pNext = tmp.head_;
  size_ += tmp.size_;
  head_ = tmp.head_;
  tmp.size_ = 0;
  tmp.rootRedirectPop();
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args &&...args) {
  list<T> tmp = {args...};
  merge(tmp);
}

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(iterator pos, Args &&...args) {
  list<T> tmp = {args...};
  list<T>::iterator it = tmp.begin();
  tmp.head_->pPrev = pos.getData()->pPrev;
  tmp.last_->pNext = pos.getData();
  pos.getData()->pPrev->pNext = tmp.head_;
  pos.getData()->pPrev = tmp.last_;
  size_ += tmp.size_;
  if (pos.getData() == head_) head_ = tmp.head_;
  if (pos.getData() == end_) last_ = tmp.last_;
  tmp.size_ = 0;
  tmp.rootRedirectPop();
  return it;
}

}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_LIST_HPP_