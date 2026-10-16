#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("", 25, 5), _target("") 
{
  std::cout << "[PresidentialPardonForm] Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form(target, 25, 5), _target(target) 
{
  std::cout << "[PresidentialPardonForm] Constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other): Form(other.getName(), 25, 5), _target(other._target) 
{
  std::cout << "[PresidentialPardonForm] Copy constructor called." << std::endl;
  this->setSigned(other.getSigned());
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &other) 
{
  std::cout << "[PresidentialPardonForm] Copy assigment operator called."
            << std::endl;
  if (this == &other)
    return *this;
  this->setSigned(other.getSigned());
  this->_target = other._target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
  std::cout << "[PresidentialPardonForm] Destructor called." << std::endl;
}

void PresidentialPardonForm::executer() const 
{
  std::cout << "[PresidentialPardonForm] " << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
