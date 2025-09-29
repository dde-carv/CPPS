/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:59:19 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:59:20 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	_newfile.open(new_file_name.c_str(), std::ios::out);
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

int		Replacer::replace(std::string s1, std::string s2)
{
	size_t		pos;
	std::string	buffer;
	int			s1_l = s1.length();
	int			s2_l = s2.length();

	while (getline(_oldfile, buffer))
	{
		pos = buffer.find(s1);
		while (pos != std::string::npos && s1_l)
		{
			buffer.erase(pos, s1_l);
			buffer.insert(pos, s2);
			_newfile << buffer.substr(0, pos + s2_l);
			buffer.erase(0, pos + s2_l);
			pos = buffer.find(s1);
		}
		_newfile << buffer;
		if(!_oldfile.eof())
			_newfile << std::endl;
	}
	return 1;
}
