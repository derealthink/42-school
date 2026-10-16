#include "ClapTrap.hpp"

//__________DEFAULT__________

ClapTrap::ClapTrap(std::string name){
    this->name = name;
    this->energyP = 10;
    this->hitP = 10;
    this->attackD = 0;
    std::cout << "Constrcutor has been called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    *this = copy;
    std::cout << "Copy constrcutor has been called" << std::endl;  
}

ClapTrap& ClapTrap:: operator=(const ClapTrap &copy){

    if (this != &copy)
    {
        this->name = copy.getName();
        this->hitP = copy.getHitP();
        this->energyP = copy.getEnergyP();
        this->attackD = copy.getAttackD();
    }
    return *this;
    std::cout << "Assignment operator called" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor has been called for " << name << std::endl;
}

//__________GETTERS__________

std::string ClapTrap:: getName() const{return (this->name);}

int ClapTrap::getAttackD() const{return (this->attackD);}

int ClapTrap::getEnergyP() const{return (this->energyP);}

int ClapTrap::getHitP() const{return (this->hitP);}

//__________SETTERS__________

void ClapTrap::setEnergyP(int val){
    this->energyP += val;
}

void ClapTrap::setHitP(int val){
    this->hitP += val;
}

//__________ATTACK/REPAIR__________

bool ClapTrap::isWorking() const {
    if (getEnergyP() < 1 || getHitP() < 1)
        return false;
    return true;
}


void ClapTrap::attack(const std::string &target){
   if (!this->isWorking()){
        std::cout << this->getName() << " cannot attack." << std::endl;
        return ;
   }
   std::cout << "ClapTrap " << this->getName() << " attacks " << target << " inflicting " << this->getAttackD() << " damage! " << std::endl;
   setEnergyP(-1);
}

void ClapTrap::takeDamage(unsigned int amount) {
    setHitP(-(int(amount)));
    std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage, OUCH!" << std::endl;
}

void ClapTrap:: beRepaired(unsigned int amount) {
    if (!this->isWorking()){
            std::cout << this->getName() << " Cannot be repaired " << std::endl;
            return ;
    }
    setHitP(int(amount));
    setEnergyP(-1);
    std::cout << this->getName() << " has repaired itself of " << amount << " points, WOW !" << std::endl;
}



