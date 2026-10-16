#include "Zombie.hpp"

int main(){
    Zombie *res = newZombie("Marika");
    res->announce();
    randomChump("Kevin");
    res->~Zombie();
}