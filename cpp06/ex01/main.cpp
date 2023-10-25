#include "Serializer.hpp"

int	main() 
{
	Data data(42);
	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Original value: " << data.getValue() << std::endl;
	std::cout << "Deserialized value: " << deserialized->getValue() << std::endl;

	if (&data == deserialized) 
	{
		std::cout << "Pointers match!" << std::endl;
	} 
	else 
	{
		std::cout << "Pointers do not match!" << std::endl;
	}

	Data newData(42);
	uintptr_t newSerialized = Serializer::serialize(&newData);
	Data* newDeserialized = Serializer::deserialize(newSerialized);

	std::cout << "Original value: " << newData.getValue() << std::endl;
	std::cout << "Deserialized value: " << newDeserialized->getValue() << std::endl;

	if (&newData == deserialized) 
	{
		std::cout << "Pointers match!" << std::endl;
	} 
	else 
	{
		std::cout << "Pointers do not match!" << std::endl;
	}

	return 0;
}
