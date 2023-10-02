#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <algorithm>


template<typename T>
class s21_vector
{
    public:
    class iterator;
    class const_iterator;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;

    

    public:
    s21_vector();
    s21_vector(size_type n);
    s21_vector(std::initializer_list<value_type> const &items);
    s21_vector(s21_vector &v);
    s21_vector(s21_vector &&v);
    s21_vector& operator= (s21_vector&&v);
    s21_vector operator= (const s21_vector&v);

    ~s21_vector();
    reference operator[](size_type pos) { return vector_[pos];};
    const_reference at(size_type pos) const;
    const_reference back() {return vector_[size_ - 1];};
    const_reference front() {return vector_[0];};
    T* data() {return vector_;};

    iterator begin() {return iterator(vector_);};
    iterator end() {return iterator(vector_ + size_ - 1);};
    const_iterator cbegin() {return const_iterator(vector_);};
    const_iterator cend() {return const_iterator(vector_ + size_ - 1);};

    bool empty() const {return vector_ != nullptr ? false : true;};
    size_type size() const {return size_;};
    size_type max_size() const {return std::numeric_limits<std::size_t>::max() / sizeof(value_type);};
    void reserve(size_type size);
    size_type capacity() const {return capacity_;};
    void shrink_to_fit();

    void clear();
    iterator insert(iterator pos, const_reference value);
    void erase(iterator pos);
    void push_back(const_reference value);
    void pop_back();
    void swap(s21_vector &other);
    
    template <typename... Args>
    iterator insert_many(iterator pos, Args &&...args);
    template <typename... Args>
    void insert_many_back(Args &&...args);

    private:
    size_type size_;
    size_type capacity_;
    T* vector_;  
    void zero_vector();
    void realloc(size_type new_size);

};

template <typename T>
class s21_vector<T>::iterator 
{
public:
    iterator(T* pointer) : pointer_(pointer) {}; 
    T* base() {return pointer_;};
    T operator*() {return *pointer_;};
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    bool operator==(iterator iter2) {return iter2.pointer_ == pointer_ ? true : false;};
    bool operator!=(iterator iter2) {return this == iter2 ? false : true;};

private:
    T* pointer_;
};

template <typename T>
class s21_vector<T>::const_iterator 
{
public:
    const_iterator(const T* pointer) : pointer_(pointer) {}; 
    const T* base() {return pointer_;};
    const T operator*() {return *pointer_;};
    const_iterator& operator++();
    const_iterator operator++(int);
    const_iterator& operator--();
    const_iterator operator--(int);
    bool operator==(const const_iterator iter2) {return iter2.pointer_ == pointer_ ? true : false;};
    bool operator!=(const const_iterator iter2) {return this == iter2 ? false : true;};
private:
    const T* pointer_;
};

#include "s21_vector.tpp"

#endif  // VECTOR_H


// int x = 5;
// int &y = x;
// y = 3; -- x = 3;