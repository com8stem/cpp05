#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5), target_("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("presidential pardon", 25, 5), target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("presidential pardon", 25, 5), target_(other.target_)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    (void)other;
    std::cout << "Form attribute is unchangeable." << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    validate_requirement(executor);
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}