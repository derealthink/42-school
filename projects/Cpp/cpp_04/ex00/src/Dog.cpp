#include "Dog.hpp"

Dog::Dog() 
{
    type = "Dog";
    std::cout << "DOG constrcutor has been called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "DOG copy constructor has been called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    std::cout << "DOG assignment operator has been called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "DOG destructor has been called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}