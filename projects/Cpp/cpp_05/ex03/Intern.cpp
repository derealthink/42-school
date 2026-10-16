// Created by tde-sous on 26-02-2024.
#include "Intern.hpp"

Intern::Intern() {
  std::cout << "[Intern] Default constructor called." << std::endl;
}

Intern::Intern(const Intern &other) {
  std::cout << "[Intern] Copy constructor called." << std::endl;
  (void)other;
}

Intern &Intern::operator=(const Intern &other) {
  std::cout << "[Intern] Copy assigment operator called." << std::endl;
  (void)other;
  return *this;
}

Intern::~Intern() { std::cout << "[Intern] Destructor called." << std::endl; }

Form *Intern::createShrubbery(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}
Form *Intern::createRobotomy(const std::string &target) const {
    return new RobotomyRequestForm(target);
}
Form *Intern::createPresidential(const std::string &target) const {
    return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    std::string names[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};

    Form *(Intern::*functions[3])(const std::string &) const = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*functions[i])(target);
        }
    }
    std::cout << "Intern error: form '" << formName << "' does not exist." << std::endl;
    return NULL;
}

