#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n===== CLAPTRAP BASIC TEST =====\n" << std::endl;

    ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    b.takeDamage(5);

    b.beRepaired(3);
    b.attack("A");

    std::cout << "\n===== ENERGY / DEATH TEST =====\n" << std::endl;

    // Drain energy
    for (int i = 0; i < 12; i++)
        a.attack("B");

    // Kill ClapTrap
    b.takeDamage(100);
    b.attack("A");      // should fail
    b.beRepaired(10);   // should fail

    std::cout << "\n===== COPY + ASSIGNMENT TEST =====\n" << std::endl;

    ClapTrap c(a); // copy constructor
    c.attack("Someone");

    ClapTrap d("D");
    d = a; // assignment operator
    d.attack("Someone else");

    std::cout << "\n===== SCAVTRAP TEST =====\n" << std::endl;

    ScavTrap s1("SCAV-1");
    ScavTrap s2("SCAV-2");

    s1.attack("SCAV-2");
    s2.takeDamage(30);

    s2.beRepaired(10);
    s2.guardGate();

    std::cout << "\n===== SCAV ENERGY / DEATH TEST =====\n" << std::endl;

    for (int i = 0; i < 55; i++)
        s1.attack("target"); // should eventually stop

    s2.takeDamage(200);
    s2.attack("SCAV-1"); // should fail

    std::cout << "\n===== SCAV COPY TEST =====\n" << std::endl;

    ScavTrap s3(s1);
    s3.guardGate();

    ScavTrap s4("temp");
    s4 = s1;
    s4.attack("copied target");

    std::cout << "\n===== END OF TESTS =====\n" << std::endl;

    return 0;
}