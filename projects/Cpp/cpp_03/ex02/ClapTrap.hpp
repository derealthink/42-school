#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
    std::string name;
    int hitP;
    int energyP;
    int attackD;
    
    public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap& operator=(const ClapTrap &copy);
    ~ClapTrap();


    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    bool isWorking()const;

    std::string getName() const;
    int getHitP() const;
    int getEnergyP() const;
    int getAttackD() const;

    void setEnergyP(int val);
    void setHitP(int val);
};

#endif