#include "easyfind.hpp"

int main() 
{
	std::list<int>	lst;

	for(int i = 0; i < 10; i++) 
	{
		lst.push_back(i + 1);
	}

	std::cout << "\nTesting list with a number in the list" << std::endl;
	try 
	{
		if (::easyfind(lst, 1))
			throw FoundException();
		else
			throw NoOccurrenceException();
	} catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}

	std::vector<int> vec;

	for(int i = 0; i < 10; i++) 
	{
		vec.push_back(i + 1);
	}

	std::cout << "\nTesting vector with a wrong number" << std::endl;
	try 
	{
		if (::easyfind(vec, 11))
			throw FoundException();
		else 
			throw NoOccurrenceException();
	} catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}