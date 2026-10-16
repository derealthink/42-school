#ifndef HUMAN_A
#define HUMAN_A 

#include "Weapon.hpp"
#include <string>

class HumanA{
    private:
        Weapon &weapon;
        std::string name;
    public:
        HumanA(std::string typeName, Weapon &typeWeapon);
        void attack();
};


#endif