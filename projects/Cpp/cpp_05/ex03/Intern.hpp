#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();

    Form *createShrubbery(const std::string &target) const;
    Form *createRobotomy(const std::string &target) const;
    Form *createPresidential(const std::string &target) const;

    Form *makeForm(const std::string &formName, const std::string &target) const;
};

#endif