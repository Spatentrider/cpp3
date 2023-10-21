#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try 
	{
		Form wrong("W1", 0, 150);
	} catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		Bureaucrat b1("B1", 51);
		Form f1("A1", 50, 50);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		b1.signForm(f1);
	} catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		Bureaucrat b2("B2", 150);
		Form f2("B1", 150, 150);
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
		b2.signForm(f2);
		b2.signForm(f2);
	} catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}