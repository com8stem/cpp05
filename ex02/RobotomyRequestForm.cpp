#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45), target_("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("robotomy request", 72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("robotomy request", 72, 45), target_(other.target_)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    (void)other;
    std::cout << "Form attribute is unchangeable." << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    validate_requirement(executor);
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int random_number = std::rand();

    if (random_number % 2 == 0)
    {
        std::cout << "Zzzzz" << std::endl;
        std::cout << getName() << " has been robotomized." << std::endl;
    }
    else
    {
        std::cout << "The robotomy failed." << std::endl;
    }
}