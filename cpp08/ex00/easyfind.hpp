#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <vector>
# include <list>

template< typename T >
bool	easyfind(const T& container, int toFind);

class	NoOccurrenceException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class	FoundException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

# include "easyfind.tpp"

#endif