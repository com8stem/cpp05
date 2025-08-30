#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name_("Default"), is_signed_(false), sign_grade_(150), execute_grade_(150) {}

AForm::AForm(const std::string &name, int sign_grade, int execute_grade)
    : name_(name), is_signed_(false), sign_grade_(sign_grade), execute_grade_(execute_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw AForm::GradeTooHighException();
    else if (sign_grade > 150 || execute_grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name_(other.name_), is_signed_(false), sign_grade_(other.sign_grade_), execute_grade_(other.execute_grade_)
{
    if (other.sign_grade_ < 1 || other.execute_grade_ < 1)
        throw AForm::GradeTooHighException();
    else if (other.sign_grade_ > 150 || other.execute_grade_ > 150)
        throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        is_signed_ = other.is_signed_;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
    return name_;
}

bool AForm::getIsSigned() const
{
    return is_signed_;
}

int AForm::getSignGrade() const
{
    return sign_grade_;
}

int AForm::getExecuteGrade() const
{
    return execute_grade_;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form Name: " << form.getName()
       << ", Is Signed(boolean): " << form.getIsSigned()
       << ", Sign Grade: " << form.getSignGrade()
       << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSignGrade())
    {
        throw AForm::GradeTooLowException();
    }
    is_signed_ = true;
}

void AForm::validate_requirement(const Bureaucrat &executor) const
{
    if (!is_signed_ || executor.getGrade() > execute_grade_)
        throw GradeTooLowException();
}
