// #include "s21_vector.hpp"
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
s21_vector<T>::s21_vector(std::initializer_list<value_type> const &items) : size_(items.size()), capacity_(items.size()),vector_(new T[items.size()])
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
    tmp.size_ = this->size_ + 1;
    size_t int_pos = pos.base() - vector_, j  = 0;
    for (size_t i  = 0; i < size_ + 1; i++)
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
    for (size_t i  = 0; i < size_; i++)
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
        std::copy(vector_, vector_ + size_, tmp.vector_);  
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
    size_t int_pos = pos.base() - vector_ + 1;
    for(size_t i = 0; i < tmp.size();i++)
    {
        insert(iterator(begin().base() + int_pos + i), tmp[i]);
    }
    return pos;
}

template <typename T>
template <typename... Args>
void s21_vector<T>::insert_many_back(Args &&...args) {
  insert_many(end(), args...);
}








    