#pragma once

#include <iostream>
#include <fstream>

class Replacer
{
	private:
		std::fstream	_oldfile;
		std::fstream	_newfile;
	public:
		Replacer();
		~Replacer();
};

