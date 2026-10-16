#include "Dog.hpp"

Dog::Dog() 
{
    type = "Dog";
    dogBrain = new Brain();
    std::cout << "DOG constrcutor has been called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
     dogBrain = new Brain(*other.dogBrain);
    std::cout << "DOG copy constructor has been called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {                    // check self-assignment
        Animal::operator=(other);            // copy base class part
        delete dogBrain;                     // free old brain
        dogBrain = new Brain(*other.dogBrain); // allocate new deep copy
        std::cout << "DOG assignment operator has been called" << std::endl;
    }
    return *this;
}

Dog::~Dog() 
{
    delete dogBrain;
    std::cout << "DOG destructor has been called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

Brain* Dog::getBrain() const {
    return dogBrain;
}
