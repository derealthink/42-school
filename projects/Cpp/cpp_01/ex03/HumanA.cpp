#include "HumanA.hpp"

HumanA::HumanA(std::string typeName, Weapon &typeWeapon) :
        weapon(typeWeapon), name(typeName) {
}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}