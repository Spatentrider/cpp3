#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	// Create bureaucrats
	Bureaucrat B1("B1", 45);
	Bureaucrat B2("B2", 5);

	// Create forms
	Shrubbery shrubbery("garden");
	Robotomy robotomy("human");
	President pardon("criminal");

	std::cout << "\033[32m" << "\n-----Initial state of the form and bureaucrats-----" << "\033[0m" << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	std::cout << B1 << std::endl;
	std::cout << B2 << std::endl;

	try {
		std::cout << "\033[32m" << "\n-----B1 tries to sign the forms-----" << "\033[0m" << std::endl;
		B1.signForm(shrubbery);
		B1.signForm(robotomy);
		B1.signForm(pardon);

		std::cout << "\033[32m" << "\n-----B2 signs the rest of the forms-----" << "\033[0m" << std::endl;
		B2.signForm(shrubbery);
		B2.signForm(robotomy);
		B2.signForm(pardon);
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\033[32m" << "\n-----Print the forms after being signed-----" << "\033[0m" << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;

	try {
		std::cout << "\033[32m" << "\n-----B1 tries to execute the forms-----" << "\033[0m" << std::endl;
		B1.executeForm(shrubbery);
		B1.executeForm(robotomy);
		B1.executeForm(pardon);

		std::cout << "\033[32m" << "\n-----B2 executes the forms-----" << "\033[0m" << std::endl;
		B2.executeForm(shrubbery);
		B2.executeForm(robotomy);
		B2.executeForm(pardon);
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\033[32m" << "\n-----Print the final state of the forms and bureaucrats-----" << "\033[0m" << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	std::cout << B2 << std::endl;
	std::cout << B1 << std::endl;

	return 0;
}
