#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), target_("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery creation", 145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("shrubbery creation", 145, 137), target_(other.target_)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    (void)other;
    std::cout << "Form attribute is unchangeable." << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    validate_requirement(executor);
    std::string filename = target_ + "_shrubbery";
    std::ofstream ostrm(filename);

    if (!ostrm)
    {
        throw std::runtime_error("Failed to open file");
    }

    ostrm << "      /\\" << std::endl;
    ostrm << "     /  \\" << std::endl;
    ostrm << "    /    \\" << std::endl;
    ostrm << "   /      \\" << std::endl;
    ostrm << "  /        \\" << std::endl;
    ostrm << "     ||||" << std::endl;
    ostrm << "     ||||" << std::endl;
    ostrm.close();
}