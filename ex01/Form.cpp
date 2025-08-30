#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name_("Default"), is_signed_(false), sign_grade_(150), execute_grade_(150) {}

Form::Form(const std::string &name, int sign_grade, int execute_grade)
    : name_(name), is_signed_(false), sign_grade_(sign_grade), execute_grade_(execute_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw Form::GradeTooHighException();
    else if (sign_grade > 150 || execute_grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : name_(other.name_), is_signed_(false), sign_grade_(other.sign_grade_), execute_grade_(other.execute_grade_)
{
    if (other.sign_grade_ < 1 || other.execute_grade_ < 1)
        throw Form::GradeTooHighException();
    else if (other.sign_grade_ > 150 || other.execute_grade_ > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        is_signed_ = other.is_signed_;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
    return name_;
}

bool Form::getIsSigned() const
{
    return is_signed_;
}

int Form::getSignGrade() const
{
    return sign_grade_;
}

int Form::getExecuteGrade() const
{
    return execute_grade_;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form Name: " << form.getName()
       << ", Is Signed(boolean): " << form.getIsSigned()
       << ", Sign Grade: " << form.getSignGrade()
       << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSignGrade())
    {
        throw Form::GradeTooLowException();
    }
    is_signed_ = true;
}
