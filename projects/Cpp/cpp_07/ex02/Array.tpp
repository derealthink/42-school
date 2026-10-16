#include "Array.hpp"

template <class T> Array<T>::Array() : size_()
{
    std::cout << "ARRAY Default Constructor Called" << std::endl;
    this->array_ = new T[0];
    this->size_ = 0;
}

template <class T> Array<T>::Array(unsigned int n) : size_(n)
{
    std::cout <<"ARRAY Constructor Called" << std::endl;
    this->array_ = new T[n];
}

template <class T> Array<T>::Array(const Array &copy)
{
    this->array_ = new T[copy.size()];
    for (unsigned int i = 0; i < copy.size(); i++)
        this->array_[i] = copy.array_[i];
    this->size_ = copy.size_;
}

template <class T> Array<T> &Array<T>::operator=(const Array &copy)
{
    if (this == &copy)
        return *this;
    delete[] this->array_;
    this->array_ = new T[copy.size()];
    for (unsigned int i = 0; i < copy.size(); i++)
        this->array_[i] = copy.array_[i];
    this->size_ = copy.size_;
    return *this;
}

template <class T> Array<T>::~Array() 
{
  delete[] this->array_;
  std::cout << "ARRAY Destructor called!" << std::endl;
}

template <class T> unsigned int Array<T>::size() const { return size_; };

template <class T> T &Array<T>::operator[](unsigned int i) 
{
  if (i >= this->size())
    throw OutOfBounds();
  return this->array_[i];
}

template <class T> const char *Array<T>::OutOfBounds::what() const throw() 
{
  return "Index is out of range.";
}