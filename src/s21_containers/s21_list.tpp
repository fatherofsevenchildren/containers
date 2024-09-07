#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_LIST_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_LIST_TPP_
#include <algorithm>
#include <iostream>
namespace s21 {
template <typename T>
class list {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 protected:
  class Node {
   public:
    Node *pNext;
    Node *pPrev;
    T data;
    explicit Node(value_type data = value_type(), Node *pNext = nullptr,
                  Node *pPrev = nullptr) {
      this->data = data;
      this->pNext = pNext;
      this->pPrev = pPrev;
    }
  };

 public:
  class ListIterator {
   public:
    ListIterator() = default;
    explicit ListIterator(Node *pNode)
        : pNode_(pNode), pNodeNext_(pNode->pNext), pNodePrev_(pNode_->pPrev){};
    T operator*() const;
    ListIterator &operator++();
    ListIterator &operator--();
    bool operator==(list<T>::ListIterator iter);
    bool operator!=(list<T>::ListIterator iter);
    Node *getData() const { return pNode_; };

   private:
    Node *pNode_;
    Node *pNodeNext_;
    Node *pNodePrev_;
  };

  class ListConstIterator {
   public:
    ListConstIterator() = default;
    explicit ListConstIterator(const Node *pNode)
        : pNode_(pNode), pNodeNext_(pNode->pNext), pNodePrev_(pNode_->pPrev){};
    T operator*() const;
    ListConstIterator &operator++();
    ListConstIterator &operator--();
    bool operator==(list<T>::ListConstIterator iter);
    bool operator!=(list<T>::ListConstIterator iter);
    Node *getData() const { return pNode_; };

   private:
    const Node *pNode_;
    const Node *pNodeNext_;
    const Node *pNodePrev_;
  };
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

 protected:
  int size_;
  Node *head_;
  Node *last_;
  Node *end_;
  void copyList(const list<T> &list);
  void redirect(list<T> &list);
  void rootRedirect();
  void rootRedirectPop();

 public:
  list();
  explicit list(size_type n);
  list(const list<T> &list);
  list(list<T> &&list) noexcept;
  list(std::initializer_list<value_type> const &items);
  ~list();

  const_reference front() const { return head_->data; };
  const_reference back() const { return last_->data; };

  iterator begin() const { return iterator(head_ != nullptr ? head_ : end_); };
  iterator end() const { return iterator(end_); };

  const_iterator cbegin() const {
    return const_iterator(head_ != nullptr ? head_ : end_);
  };
  const_iterator cend() const { return const_iterator(end_); };

  bool empty() const;
  size_type size() const { return size_; };
  size_type max_size() const;

  void clear();
  void insert(iterator pos, value_type data);
  void erase(iterator pos);
  void push_back(value_type data);
  void pop_back();
  void push_front(value_type data);
  void pop_front();
  void swap(list<T> &other);
  void merge(list<T> &other);
  void splice(iterator pos, list<T> &other);
  void reverse();
  void unique();
  void sort();
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  void insert_many_front(Args &&...args);
  template <typename... Args>
  iterator insert_many(iterator pos, Args &&...args);

  //  reference operator[](int index) const;
  list<T> &operator=(list<T> &&list) noexcept;
  list<T> &operator=(const list<T> &list);
};
}  // namespace s21

//// todo list class empty list errors

//#include "s21_list.tpp"

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_LIST_TPP_