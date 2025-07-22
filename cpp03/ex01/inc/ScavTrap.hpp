#pragma once

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_guardGate;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &object);
		~ScavTrap();

		ScavTrap		&operator=(const ScavTrap &copy);

		bool			getGardGate();
		void			setGardGate(bool mode);
		void			attack(const std::string& target);
		void			guardGate();
};


