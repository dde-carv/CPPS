/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:56:35 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/15 17:25:30 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

/************ Constructors and Destructor ************/

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "ScalarConverter default constructor called." << RST << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << GREEN << "ScalarConverter copy constructor called." << RST << std::endl;

	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;

	std::cout << YELLOW << "ScalarConverter copy assignment operator called." << RST << std::endl;

	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destructor called." << RST << std::endl;
}

/************ Member Functions ************/

void	ScalarConverter::convert(const std::string str)
{
	char	c;
	int		i;
	float	f;
	double	d;

	switch (findType(str))
	{
		case 0:
			c = str[1];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;

		case 1:
			i = atoi(str.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;

		case 2:
			f = atof(str.c_str());
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;

		case 3:
			d = atof(str.c_str());
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;

		default:
			std::cout << RED << "Invalid literal!!" << RST << std::endl;
			return ;
	}


}

/************ Other ************/

int	findType(const std::string &str)
{
	bool	dot = false;

	if (!str.compare("+inff") || !str.compare("-inff") || !str.compare("nanf"))
		return 2;
	else if (!str.compare("+inf") || !str.compare("-inf") || !str.compare("nan"))
		return 3;
	if (str[0] == '\'' && str[2] == '\'')
		return 0;
	for (int i = 0; str[i] !='\0'; i++)
	{
		
	}
}
