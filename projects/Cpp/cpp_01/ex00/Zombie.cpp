#include "Zombie.hpp"

void Zombie ::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string zombieName){
    name = zombieName;
}

Zombie::~Zombie(){
    std::cout << name << " has been Destroyed\n";
}