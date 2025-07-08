#include "Replacer.hpp"

Replacer::Replacer()
{
	std::cout << "Default constructor called." << std::endl;
}

Replacer::~Replacer()
{
	std::cout << "Default destructor called." << std::endl;
}

int	Replacer::set_new_file(std::string fname)
{
	_oldfile.open(fname.c_str(), std::ios::in);
	if (!_oldfile.is_open())
	{
		std::cout << "There is no file named \"" << fname << "\"!" << std::endl;
		return 0;
	}
	if (!_oldfile.good())
	{
		_oldfile.close();
		std::cout << "Error in opening the file \"" << fname << "\"!" << std::endl;
		return 0;
	}
	std::string new_file_name = ".replace";
	new_file_name.insert(0, fname);
	_newfile.open(fname.c_str(), std::ios::out);
	if (!_newfile.good())
	{
		_oldfile.close();
		_newfile.close();
		std::cout << "Error in opening the file \"" << fname << ".replace\"!" << std::endl;
		return 0;
	}
	return 1;
}

void	Replacer::file_closer()
{
	if (_oldfile.is_open())
		_oldfile.close();
	if (_newfile.is_open())
		_newfile.close();
}

