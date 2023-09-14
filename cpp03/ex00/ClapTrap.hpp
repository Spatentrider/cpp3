#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_attack;

	public:
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap& other );
		~ClapTrap();
		ClapTrap& operator=( const ClapTrap& other );

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif
