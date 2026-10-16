#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "CAT constructor has been called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "CAT copy constructor has been called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    Animal::operator=(other);
    std::cout << "CAT assignment operator has been called" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "CAT destructor has been called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}