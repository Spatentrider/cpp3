#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class Shrubbery : public AForm 
{
	private:
		std::string	_target;

	public:
		Shrubbery();
		Shrubbery( const std::string& target );
		Shrubbery( const Shrubbery& other );
		virtual ~Shrubbery();
		Shrubbery& operator=( const Shrubbery& other );

		virtual void	execute( Bureaucrat const& executor ) const;
};

#endif
