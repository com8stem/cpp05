#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Steve", 140);
        std::cout << bureaucrat << std::endl;
        Bureaucrat highBureaucrat("Alice", 1);
        std::cout << highBureaucrat << std::endl;

        PresidentialPardonForm form1("Form1");
        std::cout << form1 << std::endl;

        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);

        highBureaucrat.signForm(form1);
        highBureaucrat.executeForm(form1);

        RobotomyRequestForm form2("Form2");
        std::cout << form2 << std::endl;

        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);

        highBureaucrat.signForm(form2);
        highBureaucrat.executeForm(form2);

        ShrubberyCreationForm form3("Form3");
        std::cout << form3 << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);

        highBureaucrat.signForm(form3);
        highBureaucrat.executeForm(form3);
    }
    catch (const Bureaucrat::GradeTooHighException)
    {
        std::cerr << "Caught GradeTooHighException" << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException)
    {
        std::cerr << "Caught GradeTooLowException" << std::endl;
    }
    return 0;
}
