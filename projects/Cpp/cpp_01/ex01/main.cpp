#include "Zombie.hpp"

int main(){
    int n = 8;
    Zombie *Horde = zombieHorde(n, "Jeffrey");

    for (int i = 0; i < n; i++)
        Horde[i].announce();
    delete[] Horde;
}