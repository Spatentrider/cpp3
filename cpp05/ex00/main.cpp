#include "Bureaucrat.hpp"

int	main() {
	std::cout << "\033[32m" << "\n-----Bureaucrat hight grade-----" << "\033[0m" << std::endl;
	try {
		Bureaucrat b1("B1", 1);
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[32m" << "\n-----Bureaucrat low grade-----" << "\033[0m" << std::endl;
	try {
		Bureaucrat b2("B2", 150);
		std::cout << b2 << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
