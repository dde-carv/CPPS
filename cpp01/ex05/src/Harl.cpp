#include "Harl.hpp"

Harl::Harl()
{
	_level_finder[0] = "DEBUG";
	_level_finder[1] = "INFO";
	_level_finder[2] = "WARNING";
	_level_finder[3] = "ERROR";
	_level[0] = &Harl::_debug;
	_level[1] = &Harl::_info;
	_level[2] = &Harl::_warning;
	_level[3] = &Harl::_error;
	std::cout << "Default constructor called." << std::endl;
}

Harl::~Harl()
{
	std::cout << std::endl << "Default desconstructor called." << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i <= 3; i++)
	{
		if(!_level_finder[i].compare(level.c_str()))
		{
			(this->*_level[i])();
			return ;
		}
	}
	std::cout << std::endl << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
}

void	Harl::_debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup" << std::endl \
	<< " burger. I really do!" << std::endl;
}

void	Harl::_info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough" << std::endl \
	<< " bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for" << std::endl \
	<<" years, whereas you started working here just last month." << std::endl;
}

void	Harl::_error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
