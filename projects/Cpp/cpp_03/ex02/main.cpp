#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n=== BASIC CONSTRUCTION TEST ===\n" << std::endl;
    FragTrap f1("FRAG_ONE");

    std::cout << "\n=== ATTACK TEST ===\n" << std::endl;
    f1.attack("enemy");
    f1.attack("enemy");

    std::cout << "\n=== DAMAGE + REPAIR TEST ===\n" << std::endl;
    f1.takeDamage(40);
    f1.beRepaired(20);

    std::cout << "\n=== HIGH FIVE TEST ===\n" << std::endl;
    f1.highFivesGuys();

    std::cout << "\n=== ENERGY DEPLETION TEST ===\n" << std::endl;
    for (int i = 0; i < 105; i++)
        f1.attack("dummy");

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===\n" << std::endl;
    FragTrap f2(f1);

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===\n" << std::endl;
    FragTrap f3("TEMP");
    f3 = f1;

    std::cout << "\n=== MULTIPLE OBJECTS TEST ===\n" << std::endl;
    {
        FragTrap temp1("A");
        FragTrap temp2("B");
    } // <- destruction order test here

    std::cout << "\n=== MIXED INHERITANCE TEST ===\n" << std::endl;
    ClapTrap c1("CLAP");
    ScavTrap s1("SCAV");
    FragTrap f4("FRAG_TWO");

    c1.attack("target");
    s1.attack("target");
    f4.attack("target");

    std::cout << "\n=== END OF PROGRAM ===\n" << std::endl;
    return 0;
}