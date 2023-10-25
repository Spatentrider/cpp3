#include "iter.hpp"

int main() 
{
	int intArray[] = {1, 43, 77, 999, 21};
	size_t intArrayLenght = sizeof(intArray) / sizeof(intArray[0]);

	char charArray[] = {'a', 'A', 't', 'r', 'S', 'k', 'v'};
	size_t charArrayLenght = sizeof(charArray) / sizeof(charArray[0]);

	double doubleArray[] = {45.21, 7.31, 333.8, 45.31, 88.69435, 6789.45632};
	size_t doubleArrayLenght = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Int array : \n";
	iter(intArray, intArrayLenght, print_value<int>);

	std::cout << "Char array : \n";
	iter(charArray, charArrayLenght, print_value<char>);

	std::cout << "Double array : \n";
	iter(doubleArray, doubleArrayLenght, print_value<double>);
	return 0;
}
