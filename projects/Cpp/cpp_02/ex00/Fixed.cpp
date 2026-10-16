#include "Fixed.hpp"

Fixed::Fixed() : n(0) {
    std::cout << "Deafult constructor called\n";}

Fixed::Fixed(const Fixed &copy) : n(copy.n){
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &copy){
    std::cout << "Copy assignment operator called\n";
    if (this == &copy)
        return *this;
    this->setRawBits(copy.getRawBits());
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return (n);
}

void Fixed::setRawBits(const int raw){
    std::cout << "setRawBits member function called\n";
    n = raw;
}

