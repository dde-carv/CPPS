#pragma once

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_guardGate;

	public:
/************ Constructors and Destructor ************/

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &object);
		~ScavTrap();

/************ Operator ************/

		ScavTrap		&operator=(const ScavTrap &copy);

/************ Getter ************/

		bool			getGardGate();

/************ Setter ************/

		void			setGardGate(bool mode);

/************ Member Functions ************/

		void			attack(const std::string& target);
		void			guardGate();
};
