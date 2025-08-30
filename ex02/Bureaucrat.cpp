#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name_("Default"), grade_(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_)
{
    try
    {
        if (other.grade_ < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (other.grade_ > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error during copy construction: " << e.what() << std::endl;
    }
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        if (other.grade_ < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (other.grade_ > 150)
            throw Bureaucrat::GradeTooLowException();
        grade_ = other.grade_;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}

void Bureaucrat::incrementGrade()
{
    if (grade_ <= 1)
        throw Bureaucrat::GradeTooHighException();
    grade_--;
}

void Bureaucrat::decrementGrade()
{
    if (grade_ >= 150)
        throw Bureaucrat::GradeTooLowException();
    grade_++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cerr << this->getName() << " could not sign " << form.getName() << ", because the grade is low." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cerr << this->getName() << " could not execute " << form.getName() << ", because the grade is low." << std::endl;
        return;
    }
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
