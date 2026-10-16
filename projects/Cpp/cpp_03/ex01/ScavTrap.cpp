#include "ScavTrap.hpp"

//__________DEFAULT__________

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    this->name = name;
    this->energyP = 50;
    this->hitP = 100;
    this->attackD = 20;
    std::cout << "SCAV constrcutor has been called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy){
    *this = copy;
    std::cout << "SCAV copy constrcutor has been called" << std::endl;  
}

ScavTrap& ScavTrap:: operator=(const ScavTrap &copy){

    if (this != &copy)
        ClapTrap::operator=(copy);
    std::cout << "SCAV Assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "SCAV Destructor has been called for " << name << std::endl;
}

//__________ATTACK/GUARD__________

void ScavTrap::attack(const std::string &target){
   if (!this->isWorking()){
        std::cout << "SCAV " << this->getName() << " cannot attack." << std::endl;
        return ;
   }
   std::cout << "SCAV " << this->getName() << " attacks " << target << " inflicting " << this->getAttackD() << " damage! " << std::endl;
   setEnergyP(-1);
}

void ScavTrap::guardGate(){
    std::cout << "SCAV " << this->getName() << " is guarding the gate." << std::endl;
}

