#include "ClapTrap.hpp"

int main() {
    std::cout << "\n--- Creating ClapTrap A ---\n";
    ClapTrap a("Alpha");

    std::cout << "\n--- Basic actions ---\n";
    a.attack("Target Dummy");
    a.takeDamage(3);
    a.beRepaired(5);

    std::cout << "\n--- Energy depletion test ---\n";
    for (int i = 0; i < 11; i++) {
        a.attack("Wall");
    }

    std::cout << "\n--- Repair with no energy ---\n";
    a.beRepaired(5);

    std::cout << "\n--- Taking lethal damage ---\n";
    a.takeDamage(100);

    std::cout << "\n--- Try actions when 'dead' ---\n";
    a.attack("Ghost");
    a.beRepaired(10);

    std::cout << "\n--- Copy constructor test ---\n";
    ClapTrap b(a);

    std::cout << "\n--- Assignment operator test ---\n";
    ClapTrap c("Charlie");
    c = a;

    std::cout << "\n--- Independent state check ---\n";
    c.beRepaired(10);
    std::cout << "Original A HP: " << a.getHitP() << std::endl;
    std::cout << "Copy C HP: " << c.getHitP() << std::endl;

    std::cout << "\n--- End of program ---\n";
    return 0;
}