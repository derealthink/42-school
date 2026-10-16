#include "Animal.hpp"


Animal::Animal()
{
    type = "Animal";
    std::cout << "ANIMAL constructor has been called" << std::endl;
}

Animal::Animal (const Animal &other)
{
    type = other.type;
    std::cout << "ANIMAL copy contructor has been called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    type = other.type;
    std::cout << "ANIMAL assignment operator has been called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "ANIMAL destrcutor has been called" << std:: endl;
}

std::string Animal::getType() const 
{
    return type;
}

void Animal::makeSound() const 
{
    std::cout << "Some kind of generic animal sound" << std::endl;
}
