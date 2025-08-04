#pragma once

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RST "\033[0m"

# include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
/************ Constructors and Destructor ************/

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &object);
		~ClapTrap();

/************ Operators ************/

		ClapTrap		&operator=(const ClapTrap &copy);

/************ Getters ************/

		std::string		getName();
		unsigned int	getHitPoints();
		unsigned int	getEnergyPoints();
		unsigned int	getAttackDamage();

/************ Setters ************/

		void			setName(std::string name);
		void			setHitPoints(unsigned int hp);
		void			setEnergyPoints(unsigned int ep);
		void			setAttackDamage(unsigned int ad);

/************ Member Functions ************/

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};
