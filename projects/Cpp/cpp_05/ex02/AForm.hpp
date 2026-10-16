#ifndef AFORM_HPP
#define AFORM_HPP

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <iostream>
#include <string>
#include <exception>
class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
        unsigned int const _signGrade;
        unsigned int const _execGrade;
    public:
        Form();
        Form(const std::string &name, unsigned int signGrade, unsigned int execGrade);
        Form(const Form &copy);
        Form& operator=(const Form &copy);
        virtual ~Form() = 0;

        std::string getName() const;
        unsigned int getSignGrade() const;
        unsigned int getExecGrade() const;
        bool getSigned() const;
        void setSigned(bool sign);
        void beSigned(Bureaucrat &signer);
        void execute(Bureaucrat const &executor) const;
        virtual void executer() const = 0;


        class GradeTooHighException : public std::exception
        {
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            const char *what() const throw();
        };
        class FormNotSignedException : public std::exception
        {
            const char *what() const throw();
        };

};

std::ostream &operator<<(std::ostream &os, const Form &obj);


#endif
