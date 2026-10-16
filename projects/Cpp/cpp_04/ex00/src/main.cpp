#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "---- CORRECT POLYMORPHISM ----" << std::endl;

    std::cout << "Create: Animal(meta), Dog(j), Cat(i)" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Type (j): " << j->getType() << std::endl;
    std::cout << "Type (i): " << i->getType() << std::endl;

    std::cout << "Cat (i) sound: ";
    i->makeSound();
    std::cout << "Dog (j) sound: ";
    j->makeSound();
    std::cout << "Animal (meta) sound: ";
    meta->makeSound();

    std::cout << "Delete: meta, j, i" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n---- WRONG POLYMORPHISM ----" << std::endl;

    std::cout << "Create: WrongAnimal pointer (w) to WrongCat" << std::endl;
    const WrongAnimal* w = new WrongCat();

    std::cout << "Type (w): " << w->getType() << std::endl;
    std::cout << "Sound via WrongAnimal pointer (w): ";
    w->makeSound();

    std::cout << "Delete: w" << std::endl;
    delete w;

    return 0;
}
