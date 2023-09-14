#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain 
{
	protected:
		std::string		_ideas[100];

	public:
		Brain();
		Brain( const Brain &other );
		~Brain();
		Brain &operator=( const Brain &other );

};

#endif
