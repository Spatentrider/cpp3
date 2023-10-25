#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template < typename T >
class Array 
{
	private:
		T*				_array;
		unsigned int	_length;

	public:
		Array();
		explicit Array( unsigned int n );
		Array( const Array& other );
		Array& operator=( const Array& other );
		~Array();

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int	size() const;

		class WrongIndexException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
};
# include "Array.tpp"

#endif
