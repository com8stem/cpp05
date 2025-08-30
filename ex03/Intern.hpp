#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();
    AForm *makeForm(std::string form_name, std::string target);
    class FormTypeError : public std::exception
    {
    };
};

#endif