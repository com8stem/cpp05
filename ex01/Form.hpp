#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name_;
    bool is_signed_;
    const int sign_grade_;
    const int execute_grade_;

public:
    Form();
    Form(const std::string &name, int sign_grade, int execute_grade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);
    class GradeTooHighException : public std::exception
    {
    };
    class GradeTooLowException : public std::exception
    {
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif