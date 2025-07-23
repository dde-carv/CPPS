#pragma once

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &object);
		~FragTrap();

		FragTrap		&operator=(const FragTrap &copy);

		void			highFivesGuys(void);
};
