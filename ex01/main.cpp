#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Steve", 100);
        std::cout << bureaucrat << std::endl;

        Form form("Form1", 100, 100);
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        std::cout << form << std::endl;

        Form form2("Form2", 50, 50);
        std::cout << form2 << std::endl;
        bureaucrat.signForm(form2);
        std::cout << form2 << std::endl;

        Bureaucrat highBureaucrat("Alice", 1);
        std::cout << highBureaucrat << std::endl;
        highBureaucrat.signForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Caught GradeTooHighException" << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Caught GradeTooLowException" << std::endl;
    }
    return 0;
}
