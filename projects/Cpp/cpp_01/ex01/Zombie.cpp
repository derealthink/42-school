#include "Zombie.hpp"

void Zombie ::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string zombieName){
    name = zombieName;
}

Zombie::Zombie() {};

Zombie::~Zombie(){
    std::cout << name << " has been Destroyed\n";
}