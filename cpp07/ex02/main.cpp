#include "Array.hpp"

int main() 
{
	Array<int> arr1(1);
	std::cout << "arr1 size: " << arr1.size() << std::endl;

	Array<double> arr2(5);
	std::cout << "arr2 size: " << arr2.size() << std::endl;

	for (unsigned int i = 0; i < arr2.size(); ++i) 
	{
		arr2[i] = 0.5 * (i + 1);
		std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
	}

	try 
	{
		std::cout << "arr2[10]: ";
		std::cout << arr2[10] << std::endl;
	} catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}

	Array<int> arr3 = arr1;
	Array<int> arr4;
	arr4 = arr3;

	arr3[0] = 10;
	std::cout << "arr3[0]: " << arr3[0] << std::endl;
	std::cout << "arr4[0]: " << arr4[0] << std::endl;

	return 0;
}
