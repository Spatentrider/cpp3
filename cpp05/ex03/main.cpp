#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {

	try{
		Intern someRandomIntern;
		AForm* rrf;
		AForm* prf;
		AForm* wrong;
		Bureaucrat b1("B1", 1);

		std::cout << "\033[32m" << "\n-----Initial state of the form and bureaucrats-----" << "\033[0m" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		prf = someRandomIntern.makeForm("presidential request", "P1");
		wrong = someRandomIntern.makeForm("wrong request", "W1");
		std::cout << b1 << std::endl;

		std::cout << "\033[32m" << "\n-----Bureaucrat signs and execute the forms-----" << "\033[0m" << std::endl;
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
		b1.signForm(*prf);
		b1.executeForm(*prf);
		delete rrf;
		delete prf;
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
