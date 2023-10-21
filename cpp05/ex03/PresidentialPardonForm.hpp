#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class President : public AForm 
{
	private:
		std::string	_target;

	public:
		President();
		President( const std::string& target );
		President( const President& other );
		virtual ~President();
		President& operator=( const President& other );

		virtual void	execute( Bureaucrat const& executor ) const;
};

#endif
