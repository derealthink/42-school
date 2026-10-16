#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Jhon Pork"), _grade(100)
{
    std::cout << "BUREAUCRAT Default Constrcutor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : _name(name)
{
    std::cout << "BUREAUCRAT Constructor called." << std::endl;
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade() {
  std::cout << "BUREAUCRAT Copy Constructor called." << std::endl;
  *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "BUREAUCRAT Copy Assignment called." << std::endl;
  if (this == &other)
    return *this;
  this->_grade = other._grade;
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "BUREAUCRAT Destructor called." << std::endl;
}

void Bureaucrat::decrementGrade() {
  if (this->_grade + 1 > MIN_GRADE)
    throw GradeTooLowException();
  this->_grade++;
}

void Bureaucrat::incrementGrade() {
  if (this->_grade - 1 < MAX_GRADE)
    throw GradeTooHighException();
  this->_grade--;
}

unsigned int Bureaucrat::getGrade() const { return this->_grade; }

std::string Bureaucrat::getName() const { return this->_name; }

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too High!");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too Low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) 
{
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "."
     << std::endl;
  return os;
}
