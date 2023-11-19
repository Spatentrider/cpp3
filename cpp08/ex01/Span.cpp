#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int number) : _size(number) {}

Span::Span(const Span& other) 
{
	_size = other._size;
	_numbers = other._numbers;
}

Span& Span::operator=(const Span& other) 
{
	if (this != &other) 
	{
		_size = other._size;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) 
{
	if (_numbers.size() >= _size)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::const_iterator it1, std::vector<int>::const_iterator it2) 
{
	int count = std::distance(it1, it2);
	if (_numbers.size() + count > _size) 
		throw std::runtime_error("Not enough space in Span to add all numbers");
	_numbers.insert(_numbers.end(), it1, it2);
}

int Span::shortestSpan() const 
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers in Span");
	std::vector<int> sortNumbers(_numbers);
	std::sort(sortNumbers.begin(), sortNumbers.end());
	int shortest = sortNumbers[1] - sortNumbers[0];
	for (int i = 2; i < sortNumbers.size(); i++) 
	{
		int tmp = sortNumbers[i] - sortNumbers[i - 1];
		if (tmp < shortest)
			shortest = tmp;
	}
	return shortest;
}

int Span::longestSpan() const 
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers in Span");
	std::vector<int> sortNumbers(_numbers);
	std::sort(sortNumbers.begin(), sortNumbers.end());
	return sortNumbers.back() - sortNumbers.front();
}

void Span::printVector() const 
{
	std::cout << "Span: ";
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); it++) 
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}