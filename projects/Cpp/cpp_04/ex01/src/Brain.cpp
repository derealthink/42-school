#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "BRAIN default constrcutor has been called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    *this = copy;
}

Brain& Brain::operator=(const Brain &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = copy.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "BRAIN destructor has been called" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index < 0 || index >= 100)
        return;
    ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
        return "";
    return ideas[index];
}
