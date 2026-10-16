
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "easyfind: value not found";
    }
};

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ValueNotFoundException();
    return it;
}

#endif
