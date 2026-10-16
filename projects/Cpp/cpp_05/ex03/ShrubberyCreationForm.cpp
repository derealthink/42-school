#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("", 145, 137), _target("") 
{
  std::cout << "[ShrubberyCreationForm] Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form(target, 145, 137), _target(target) 
{
  std::cout << "[ShrubberyCreationForm] Constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other._target) 
{
  std::cout << "[ShrubberyCreationForm] Copy constructor called." << std::endl;
  this->setSigned(other.getSigned());
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) 
{
  std::cout << "[ShrubberyCreationForm] Copy assignment operator called."
            << std::endl;
  if (this == &other)
    return *this;
  this->_target = other._target;
  this->setSigned(other.getSigned());
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
  std::cout << "[ShrubberyCreationForm] Destructor called." << std::endl;
}

void ShrubberyCreationForm::executer() const 
{
  std::cout << "[ShrubberyCreationForm] Drawing shrubbery for " << this->_target << "." << std::endl;
  std::cout << "   **" << std::endl;
  std::cout << "  (  ) " << std::endl;
  std::cout << " (    ) " << std::endl;
  std::cout << "(__  __) " << std::endl;
  std::cout << "   || " << std::endl;
}
