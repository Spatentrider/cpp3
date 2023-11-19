#include "Span.hpp"

int main() 
{
	std::cout << "Subject main" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printVector();
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest spam: "<< sp.longestSpan() << std::endl;
	try 
	{
		std::vector<int> vec(15000);
		std::srand(static_cast<unsigned>(time(0)));
		std::generate(vec.begin(), vec.end(), std::rand);

		Span test(vec.size());

		test.addNumbers(vec.begin(), vec.end());
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
		test.addNumber(42);
	} catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}