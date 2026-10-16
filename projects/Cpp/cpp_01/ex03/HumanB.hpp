#ifndef HUMAN_B
#define HUMAN_B 

#include "Weapon.hpp"
#include <string>

class HumanB{
    private:
        Weapon *weapon;
        std::string name;
    public:
        explicit HumanB(std::string typeName);
        void setWeapon(Weapon &typeWeapon);
        void attack();
};


#endif