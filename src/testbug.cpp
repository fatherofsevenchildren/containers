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
    // void set_pointer(T* pointer)
private:
    const T* pointer_;
};


template<typename T>
void s21_vector<T>::zero_vector()
{
    size_ = 0;
    capacity_ = 0;
    vector_ = nullptr; 
}

template<typename T>
s21_vector<T>::s21_vector() : size_(0), capacity_(0), vector_(nullptr)
{
}


template<typename T>
s21_vector<T>::s21_vector(size_type n) : size_(n), capacity_(n)
{
    vector_ = new T[capacity_] ();
    // fill_n(vector_, n, value_type());
}

template<typename T>
s21_vector<T>::s21_vector(std::initializer_list<value_type> const &items) : capacity_(items.size()), size_(items.size()),vector_(new T[items.size()])
{
    std::copy(items.begin(), items.end(), vector_); 
}


template<typename T>
s21_vector<T>::s21_vector(s21_vector &v) : size_(v.size_), capacity_(v.size_), vector_(new value_type[v.size_])
{
    std::copy(v.vector_, v.vector_ + v.size_, vector_);
}

template<typename T>
s21_vector<T>::s21_vector(s21_vector &&v) : size_(v.size_), capacity_(v.size_), vector_(v.vector_)
{
    v.zero_vector();
}

template<typename T>
s21_vector<T>::~s21_vector()
{
    if (vector_ != nullptr) delete [] vector_;
    zero_vector();
}

// при конструкторе копирования капасити будет равен сайзу а не капасити 
// NB проверить это после реализации фунуции push_back



template<typename T>
s21_vector<T> s21_vector<T>::operator= (const s21_vector&v)
{
    s21_vector<T>res(v);
    return res;
}

template<typename T>
s21_vector<T>& s21_vector<T>::operator= (s21_vector&&v)
{
    swap(v);
    if (v.vector_ != nullptr) delete [] v.vector_;
    v.zero_vector();
    return *this;
}

template<typename T>
void s21_vector<T>::swap(s21_vector<T>&other) 
{
    std::swap(vector_, other.vector_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}




template<typename T>
typename s21_vector<T>::const_reference s21_vector<T>::at(size_type pos) const
{
    if(pos > size_) {
        throw std::out_of_range("inncorect");
    }
    return vector_[pos];
}


template<typename T>
void s21_vector<T>::realloc(size_type new_size) 
{
    T* carrunt_vector = new T[new_size] (); 
    std::copy(vector_, vector_ + size_, carrunt_vector);
    delete [] vector_;
    vector_ = carrunt_vector;
    capacity_ = new_size;
}

template<typename T>
void s21_vector<T>::reserve(size_type size) 
{
    if(size <= capacity_) {
        return;
    }
    if(size > max_size()) {
        throw std::out_of_range("ReserveError: Too large size for a new capacity");
    }
    realloc(size);
}


template<typename T>
void s21_vector<T>::shrink_to_fit() 
{
    if(size_ == capacity_) {
        return;
    }
    realloc(size_);
}

template<typename T>
typename s21_vector<T>::iterator & s21_vector<T>::iterator::operator++()
{
    ++pointer_;
    return *(this);
}

template<typename T>
typename s21_vector<T>::iterator & s21_vector<T>::iterator::operator--()
{
    --pointer_;
    return *(this);
}

template<typename T>
typename s21_vector<T>::iterator s21_vector<T>::iterator::operator++(int)
{
    T* tmp = pointer_;
    ++pointer_;
    return iterator(tmp);

}

template<typename T>
typename s21_vector<T>::iterator s21_vector<T>::iterator::operator--(int)
{
    T* tmp = pointer_;
    --pointer_;
    return iterator(tmp);

}

template<typename T>
typename s21_vector<T>::const_iterator & s21_vector<T>::const_iterator::operator++()
{
    ++pointer_;
    return *(this);
}

template<typename T>
typename s21_vector<T>::const_iterator & s21_vector<T>::const_iterator::operator--()
{
    --pointer_;
    return *(this);
}

template<typename T>
typename s21_vector<T>::const_iterator s21_vector<T>::const_iterator::operator++(int)
{
    const T* tmp = pointer_;
    ++pointer_;
    return const_iterator(tmp);

}

template<typename T>
typename s21_vector<T>::const_iterator s21_vector<T>::const_iterator::operator--(int)
{
    const T* tmp = pointer_;
    --pointer_;
    return const_iterator(tmp);

}

template<typename T>
void s21_vector<T>::clear() 
{
    std::fill(vector_, vector_ + size_, 0);
    size_ = 0;
}

template<typename T>
typename s21_vector<T>::iterator s21_vector<T>::insert(iterator pos, const_reference value)
{
    s21_vector<T> tmp(size_ == capacity_ ? size_ * 2 : capacity_);
    tmp.size_ = size_ + 1;
    size_t int_pos = pos.base() - vector_, j  = 0;
    for (int i  = 0; i < size_ + 1; i++)
    {
        if(i == int_pos)
        {
            tmp[i] = value;
        } else 
        {
            tmp[i] = vector_[j++];    
        }
    }
    *this = std::move(tmp);
    return iterator(vector_ + int_pos);
}

template<typename T>
void s21_vector<T>::erase(iterator pos)
{
    size_t int_pos = pos.base() - vector_, j  = 0;
    for (int i  = 0; i < size_; i++)
    {
        if(i != int_pos)
        {
            vector_[j++] = vector_[i];    
        }
    }
    size_--;
    return;
}

template<typename T>
void s21_vector<T>::push_back(const T& value)
{
    if(max_size() <= size_) {
        throw std::out_of_range("inncorect");
    }
    if(size_ == capacity_) {
        s21_vector<T> tmp(size_ * 2);
        tmp.size_ = size_ + 1;
        std::copy(vector_, vector_ + size_ - 1, tmp.vector_);  
        tmp.vector_[size_] = value;
        *this = std::move(tmp);
    } else {
        vector_[size_++] = value;
    }
    return;
}

template<typename T>
void s21_vector<T>::pop_back()
{
    if(size_ > 0) { size_--;}    
    return;
}

template <typename T>
template <typename... Args>
typename s21_vector<T>::iterator s21_vector<T>::insert_many(iterator pos,Args &&...args) 
{
    s21_vector<T> tmp {args...};
    iterator res = pos;
    // size_t int_pos = pos.base() - vector_;
    for(size_t i = 0; i < tmp.size();i++)
    {
        std::cout << *pos << std::endl;
        insert(pos++, tmp[i]);
        std::cout << tmp[i] << std::endl;
    }
    return res;
}

using namespace std;

int main() {
    s21_vector<int> test1 = {1,2,3,4,5};
    // test1.push_back(4);
    // s21_vector<int>::
    // test1.pop_back();
    s21_vector<int>::iterator it = test1.begin();
    it++;
    test1.insert_many(it, 9,8);
    for (int i = 0; i < test1.size(); i++) {
      cout << test1[i] << endl;
    }
    // cout << test2.capacity() << endl;
    // cout << test2.size() << endl;
    // cout << *it;
    return 0;
}

