#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

class Span 
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_size;

	public:
		Span();
		Span( unsigned int number );
		Span( const Span& other );
		Span& operator=( const Span& other );
		~Span();

		void addNumber( int number );
		void addNumbers( std::vector<int>::const_iterator it1, std::vector<int>::const_iterator it2 );
		int shortestSpan() const ;
		int longestSpan() const ;
		void printVector() const;
};

#endif