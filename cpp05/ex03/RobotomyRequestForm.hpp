#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class Robotomy : public AForm 
{
	private:
		std::string	_target;

	public:
		Robotomy();
		Robotomy( const std::string& target );
		Robotomy( const Robotomy& other );
		virtual ~Robotomy();
		Robotomy& operator=( const Robotomy& other);

		virtual void	execute( Bureaucrat const& executor ) const;
};

#endif
