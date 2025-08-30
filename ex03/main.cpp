#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Intern intern;
        Bureaucrat highBureaucrat("Alice", 1);
        std::cout << highBureaucrat << std::endl;

        AForm *af;
        std::cout << "====================" << std::endl;
        af = intern.makeForm("presidential pardon", "Form1");
        std::cout << *af << std::endl;

        highBureaucrat.signForm(*af);
        highBureaucrat.executeForm(*af);
        delete af;

        std::cout << "====================" << std::endl;
        af = intern.makeForm("robotomy request", "Form2");
        std::cout << *af << std::endl;

        highBureaucrat.signForm(*af);
        highBureaucrat.executeForm(*af);
        delete af;

        std::cout << "====================" << std::endl;
        af = intern.makeForm("shrubbery create", "Form3");
        std::cout << *af << std::endl;

        highBureaucrat.signForm(*af);
        highBureaucrat.executeForm(*af);
        delete af;

        std::cout << "====================" << std::endl;
        af = intern.makeForm("not found", "Form4");
        std::cout << *af << std::endl;
        delete af;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
