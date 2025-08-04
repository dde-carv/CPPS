#pragma once

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
/************ Constructors and Destructor ************/

		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &object);
		~FragTrap();

/************ Operator ************/

		FragTrap		&operator=(const FragTrap &copy);

/************ Member Function ************/

		void			highFivesGuys(void);
};
