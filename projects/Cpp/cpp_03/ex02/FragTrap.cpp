#include "FragTrap.hpp"

//__________DEFAULT__________

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    this->name = name;
    this->energyP = 100;
    this->hitP = 100;
    this->attackD = 30;
    std::cout << "FRAG constrcutor has been called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy){
    *this = copy;
    std::cout << "FRAG copy constrcutor has been called" << std::endl;  
}

FragTrap& FragTrap:: operator=(const FragTrap &copy){

    if (this != &copy)
        ClapTrap::operator=(copy);
    std::cout << "FRAG Assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FRAG Destructor has been called for " << name << std::endl;
}

//__________ATTACK/HIGH5__________

void FragTrap::attack(const std::string &target){
   if (!this->isWorking()){
        std::cout << "FRAG " << this->getName() << " cannot attack." << std::endl;
        return ;
   }
   std::cout << "FRAG " << this->getName() << " attacks " << target << " inflicting " << this->getAttackD() << " damage! " << std::endl;
   setEnergyP(-1);
}


void FragTrap::highFivesGuys(){
    std::cout << "FRAG " << this->getName() << " is requesting a high five! don't leave FRAG " << this->getName() << " Hanging...." << std::endl;
}

