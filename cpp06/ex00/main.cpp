#include "ScalarConverter.hpp"

#define ERROR "Usage: ./convert + char || int || float || double"

int main(int argc, char** argv) 
{
	if (argc != 2) 
	{
		std::cout << ERROR << std::endl;
		return(1);
	}
	std::string input = argv[1];
	for(int i = 0; i < 6; i++) 
	{
		if (input == special[i]) 
		{
			ScalarConverter::convert(input);
			return(0);
		}
	}
	int dot = 0;
	int ef = 0;
	if (input.length() > 1) 
	{
		for (int i = 0; i < input.length(); i++) 
		{
			if (input[i] == '.')
			{
				dot++;
			} 
			else if (input[i] == 'f') 
			{
				ef++;
			} 
			else if (!std::isdigit(input[i]) || dot > 1 || ef > 1) 
			{
				std::cout << ERROR << std::endl;
				return(1);
			}
		}
		if (dot > 1 || ef > 1) 
		{
			std::cout << ERROR << std::endl;
			return(1);
		}
	}
	ScalarConverter::convert(input);

	return 0;
}
