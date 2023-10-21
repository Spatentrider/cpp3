#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() 
{
	Bureaucrat B1("B1", 45);
	Bureaucrat B2("B2", 5);
	Shrubbery shrubbery("garden");
	Robotomy robotomy("human");
	President pardon("criminal");

	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;
	try 
	{
		B1.signForm(shrubbery);
		B1.signForm(robotomy);
		B1.signForm(pardon);
		B2.signForm(shrubbery);
		B2.signForm(robotomy);
		B2.signForm(pardon);
	} catch (const std::exception & e) 
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;

	try 
	{
		B1.executeForm(shrubbery);
		B1.executeForm(robotomy);
		B1.executeForm(pardon);
		B2.executeForm(shrubbery);
		B2.executeForm(robotomy);
		B2.executeForm(pardon);
	} catch (const std::exception & e) 
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	std::cout << B2 << std::endl;
	std::cout << B1 << std::endl;

	return 0;
}
