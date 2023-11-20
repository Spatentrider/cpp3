#include "BitcoinExchange.hpp"

int main(int argc, char** argv) 
{
	if (argc != 2) 
	{
		std::cerr << "Error: No file specified" << std::endl;
		return 1;
	}
	Bitcoin bit;
	return bit.bitExchange(argv[1]);
}