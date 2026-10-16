#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("", 72, 45), _target("") 
{
  std::cout << "[RobotomyRequestForm] Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form(target, 72, 45), _target(target) 
{
  std::cout << "[RobotomyRequestForm] Constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form(other.getName(), 72, 45) 
{
  std::cout << "[RobotomyRequestForm] Copy constructor constructor called." << std::endl;
  this->setSigned(other.getSigned());
  this->_target = other._target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
  std::cout << "[RobotomyRequestForm] Copy assignment operator constructor called." << std::endl;
  if (this == &other)
    return *this;
  this->setSigned(other.getSigned());
  this->_target = other._target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
  std::cout << "[RobotomyRequestForm] Destructor called." << std::endl;
}

void RobotomyRequestForm::executer() const 
{
  std::cout << "[RobotomyRequestForm] " << this->_target << " is being robotomized." << std::endl;
  std::cout << "[RobotomyRequestForm] Drilling noises..." << std::endl;

  if (rand() % 2)
    std::cout << "[RobotomyRequestForm] " << this->_target << " has been successfully robotomized." << std::endl;
  else
    std::cout << "[RobotomyRequestForm] " << this->_target << " robotomy failed." << std::endl;
}
