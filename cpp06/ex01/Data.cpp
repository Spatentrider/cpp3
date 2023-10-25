#include "Data.hpp"

Data::Data() : _value(0) {}

Data::Data(int value) : _value(value) {}

Data::Data(const Data& other) : _value(other._value) {}

Data::~Data() {}

Data& Data::operator=(const Data& other) 
{
	if (this != &other)
		this->_value = other.getValue();
	return *this;
}

int Data::getValue() const 
{
	return this->_value;
}