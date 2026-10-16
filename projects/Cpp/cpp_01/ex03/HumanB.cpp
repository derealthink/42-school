#include "HumanB.hpp"

HumanB::HumanB(std::string typeName) : weapon(0), name(typeName) {
}

void HumanB::setWeapon(Weapon &typeClub) {
    weapon = &typeClub;
}

void HumanB::attack() {
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}