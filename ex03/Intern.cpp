#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    std::string form_names[] = {"presidential pardon", "robotomy request", "shrubbery create"};
    int form_type = sizeof(form_names) / sizeof(form_names[0]);
    int i;

    for (i = 0; i < form_type; i++)
    {
        if (form_names[i] == form_name)
            break;
    }
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << form_name << std::endl;
        return new PresidentialPardonForm(target);
    case 1:
        std::cout << "Intern creates " << form_name << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates " << form_name << std::endl;
        return new ShrubberyCreationForm(target);
    default:
        std::cout << "Intern couldn't create " << form_name << std::endl;
        throw FormTypeError();
    }
}