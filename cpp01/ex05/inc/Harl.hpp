#pragma once

#include <iostream>

class Harl
{
private:
	void		_debug();
	void		_info();
	void		_warning();
	void		_error();
	void		(Harl::*_level[4])();
	std::string	_level_finder[4];
public:
	Harl();
	~Harl();
	void	complain(std::string level);
};
