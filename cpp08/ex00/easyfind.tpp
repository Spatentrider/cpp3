#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template<typename T>
bool	easyfind(const T& container, int toFind) 
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
	return it != container.end();
}

const char* NoOccurrenceException::what() const throw() 
{
	return "No occurrence found";
}

const char* FoundException::what() const throw() 
{
	return "Number found!";
}

#endif