#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog : public Animal 
{
	private:
		Brain *_brain;

	public:
		Dog();
		Dog( const Dog &other );
		~Dog();
		Dog &operator=( const Dog &other );

		virtual void	makeSound() const;
};

#endif
