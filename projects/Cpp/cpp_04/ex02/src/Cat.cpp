#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    catBrain = new Brain();
    std::cout << "CAT constructor has been called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    catBrain = new Brain(*other.catBrain); //deep copy
    std::cout << "CAT copy constructor has been called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {                    // check self-assignment
        Animal::operator=(other);            // copy base class part
        delete catBrain;                     // free old brain
        catBrain = new Brain(*other.catBrain); // allocate new deep copy
        std::cout << "CAT assignment operator has been called" << std::endl;
    }
    return *this;
}

Cat::~Cat() {
    delete catBrain;
    std::cout << "CAT destructor has been called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() const {
    return catBrain;
}

