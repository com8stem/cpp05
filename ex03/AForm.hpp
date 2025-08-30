#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string name_;
    bool is_signed_;
    const int sign_grade_;
    const int execute_grade_;

public:
    AForm();
    AForm(const std::string &name, int sign_grade, int execute_grade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;
    void validate_requirement(const Bureaucrat &executor) const;
    class GradeTooHighException : public std::exception
    {
    };
    class GradeTooLowException : public std::exception
    {
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif