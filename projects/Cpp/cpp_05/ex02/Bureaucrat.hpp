#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
    private:
        std::string const _name;
        unsigned int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int const &grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat& operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        std::string getName() const;
        unsigned int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(const Form *signedForm, const std::string& reason);
        void executeForm(Form const &form) const;

        class GradeTooHighException : public std::exception
        {
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            const char *what() const throw();
        };

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);


#endif
