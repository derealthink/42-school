#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
    private:
        T *array_;
        unsigned int size_;
    
    public:
    Array();
    Array(unsigned int n);
    Array(const Array &copy);
    Array& operator= (const Array &copy);
    ~Array();
    
    T &operator[](unsigned int i);
    
    unsigned int size() const;
    
    class OutOfBounds : public std::exception
    {
        const char *what() const throw();
    };
};

#include "Array.tpp"

#endif