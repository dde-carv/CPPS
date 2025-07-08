#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

class Replacer
{
	private:
		std::fstream	_oldfile;
		std::fstream	_newfile;
	public:
		Replacer();
		~Replacer();
		void	file_closer();
		int		set_new_file(std::string fname);
		int		replace(std::string s1, std::string s2);
};

