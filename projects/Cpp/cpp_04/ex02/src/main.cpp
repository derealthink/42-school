#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "---- CORRECT POLYMORPHISM ----" << std::endl;

    std::cout << "Create: Dog(j), Cat(i)" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // const Animal* meta = new Animal(); // ❌ should not compile (abstract class)

    std::cout << "Type (j): " << j->getType() << std::endl;
    std::cout << "Type (i): " << i->getType() << std::endl;

    std::cout << "Cat (i) sound: ";
    i->makeSound();
    std::cout << "Dog (j) sound: ";
    j->makeSound();

    std::cout << "Delete: meta, j, i" << std::endl;
    delete j;
    delete i;
    //delete meta;

    return 0;
}
