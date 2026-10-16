#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, const unsigned int signGrade, const unsigned int execGrade) 
    : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "FORM Constructor called." << std::endl;
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    this->_signed = false; 
}

Form::Form()
    : _name("Form 0"), _signed(false), _signGrade(150), _execGrade(150)
{
    std::cout << "FORM Default Constructor called." << std::endl;
}

Form::Form(const Form &copy) 
    : _name(copy._name), _signed(copy._signed), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
    std::cout << "FORM Copy Constructor called." << std::endl;
}

Form &Form::operator=(const Form &copy) 
{
  std::cout << "[Form] Copy assignment operator called." << std::endl;
  if (this == &copy)
    return (*this);
  this->_signed = copy._signed;

  return *this;
}

Form::~Form()
{
    std::cout << "FORM Destructor called." << std::endl;
}

std::string Form::getName() const 
{
    return(this->_name);
}

unsigned int Form::getSignGrade() const
{
    return (this->_signGrade);
}

unsigned int Form::getExecGrade() const
{
    return (this->_execGrade);
}

bool Form::getSigned() const 
{
    return (this->_signed);
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("FORM |Exception| Grade is too High!");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("FORM |Exception| Grade is too Low!");
}

void Form::beSigned(Bureaucrat &signer) {

  if (this->getSigned())
    signer.signForm(this, "Form was already signed");
  else if (this->getSignGrade() < signer.getGrade()) {
    signer.signForm(this, "grade is too low");
    throw Form::GradeTooLowException();
  } else {
    signer.signForm(this, "");
    this->_signed = true;
  }
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << "This form is named: " << obj.getName() << ", and its "
    << (obj.getSigned() ? "signed " : "not signed ")
    << "the required grade to sign it, is " << obj.getSignGrade()
    << " and the required grade to execute it, is " << obj.getExecGrade();
  return os;
}
