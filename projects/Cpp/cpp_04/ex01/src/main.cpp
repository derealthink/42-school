#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void printSection(const std::string &title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
    printSection("Polymorphism: Animal pointers");
    const int count = 4;
    Animal* animals[count];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < count; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < count; ++i)
        delete animals[i];

    printSection("WrongAnimal: no virtual sound");
    WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;

    printSection("Deep copy: Dog copy constructor");
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Bone");
    Dog copiedDog(originalDog);
    copiedDog.getBrain()->setIdea(0, "Ball");

    std::cout << "Original Dog idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea[0]:   " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Original Brain addr:  " << originalDog.getBrain() << std::endl;
    std::cout << "Copied Brain addr:    " << copiedDog.getBrain() << std::endl;

    printSection("Deep copy: Cat assignment operator");
    Cat originalCat;
    originalCat.getBrain()->setIdea(1, "Sunbeam");
    Cat assignedCat;
    assignedCat = originalCat;
    assignedCat.getBrain()->setIdea(1, "Box");

    std::cout << "Original Cat idea[1]: " << originalCat.getBrain()->getIdea(1) << std::endl;
    std::cout << "Assigned Cat idea[1]: " << assignedCat.getBrain()->getIdea(1) << std::endl;
    std::cout << "Original Brain addr:  " << originalCat.getBrain() << std::endl;
    std::cout << "Assigned Brain addr:  " << assignedCat.getBrain() << std::endl;

    printSection("Shallow alias example");
    Brain* aliasBrain = originalDog.getBrain();
    aliasBrain->setIdea(2, "Alias");
    std::cout << "Original Dog idea[2]: " << originalDog.getBrain()->getIdea(2) << std::endl;
    std::cout << "Alias Brain addr:     " << aliasBrain << std::endl;

    return 0;
}
