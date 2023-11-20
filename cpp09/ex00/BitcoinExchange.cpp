#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() 
{
	std::ifstream data("data.csv");
	std::string line = "";
	std::getline(data, line);

	while (std::getline(data, line)) 
	{
		float number = 0.0;
		size_t commaIndex = line.find(',');
		std::string valueStr = line.substr(commaIndex + 1);
		std::istringstream iss(valueStr);
		iss >> number;
		_data[line.substr(0, commaIndex)] = number;
	}
	data.close();
}

Bitcoin::Bitcoin(const Bitcoin& other) 
{
	_data = other._data;
}

Bitcoin& Bitcoin::operator=(const Bitcoin& other) 
{
	if (this != &other) 
	{
		_data = other._data;
	}
	return *this;
}

Bitcoin::~Bitcoin() {}

int Bitcoin::bitExchange(char* argv) 
{
	std::ifstream input(argv);
	if (!input.good()) 
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::string line;
	std::getline(input, line);
	while (std::getline(input, line)) 
	{
		check_convert(line);
	}
	input.close();
	return 0;
}

void Bitcoin::check_convert(std::string line) 
{
	if (!check_data(line)) 
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string dataLine = line.substr(0, 10);
	std::string valueStr = line.substr(13, line.size() - 13);

	if (!check_time(dataLine)) 
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	if (!check_value(valueStr)) 
	{
		std::cout << "Error: not a positive number" << std::endl;
		return;
	}

	float valueFloat = 0.0f;
	std::istringstream(valueStr) >> valueFloat;
	if (valueFloat > 1000) 
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	std::map<std::string, float>::iterator it = _data.upper_bound(dataLine);
	if (it != _data.begin())
		it--;
	std::cout << dataLine << " => " << valueFloat << " = " << valueFloat * it->second << std::endl;
}

bool	Bitcoin::check_data(std::string data) 
{
	if (data.size() < 13) 
	{
		return false;
	}
	for (int i =0; data[i]; i++) 
	{
		if (!isdigit(data[i]) && (i <= 3 || i == 5 || i == 6 || i == 8 || i == 9))
			return false;
		if (data[i] != '-' && (i == 4 || i == 7))
			return false;
		if (data[i] != ' ' && (i == 10 || i == 12))
			return false;
		if (data[i] != '|' && i == 11)
			return false;
	}
	return true;
}

bool Bitcoin::check_time(std::string data) 
{
	std::string year = data.substr(0, 4);
	std::string month = data.substr(5, 2);
	std::string day = data.substr(8, 2);

	int yearI , monthI, dayI;
	std::istringstream(year) >> yearI;
	std::istringstream(month) >> monthI;
	std::istringstream(day) >> dayI;

	if (yearI > 2022 || yearI < 2009)
		return false;
	if (monthI > 12 || monthI < 1)
		return false;
	if (dayI > 31 || dayI < 1)
		return false;
	return true;
}

bool	Bitcoin::check_value(std::string value) 
{
	int dot = 0;

	for (int i = 0; i < value.size(); i++) 
	{
		if (!isdigit(value[i]) && value[i] != '.')
			return false;
		if (value[i] == '.')
			dot++;
		else if (dot > 1)
			return false;
	}
	return true;
}