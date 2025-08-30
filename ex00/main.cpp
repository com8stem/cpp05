#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Steve", 50);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << "After increment: " << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        std::cout << "After decrement: " << bureaucrat << std::endl;

        Bureaucrat bureaucrat2("Low", 151);
        std::cout << bureaucrat2 << std::endl;

        Bureaucrat bureaucrat3("High", 0);
        std::cout << bureaucrat3 << std::endl;

        Bureaucrat bureaucrat4("Low2", 150);
        bureaucrat4.incrementGrade();
        std::cout << "After increment: " << bureaucrat4 << std::endl;

        Bureaucrat bureaucrat5("High2", 1);
        bureaucrat5.decrementGrade();
        std::cout << "After decrement: " << bureaucrat5 << std::endl;
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
