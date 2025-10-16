/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:56:35 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/16 17:09:20 by dde-carv         ###   ########.fr       */
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

void	ScalarConverter::convert(std::string str)
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
	if (-2147483649 < d && 2147483648 > d)
	{
		std::cout << "char: ";
		if (c >= 32 && c <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	if (d == static_cast<int>(d))
	{
		std::cout << std::fixed;
		std::cout << "float: " << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
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
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue ;
		else if (str[i] == '.')
		{
			if (dot)
				return 42;
			dot = true;
		}
		else if (i != 0 && str[i + 1] == '\0' && dot && str[i] == 'f')
			return 2;
		else if (str[i] < '0' || str[i] > '9')
			return 42;
	}
	if (dot)
		return 3;
	else
	{
		if (atol(str.c_str()) > 2147483647 || atol(str.c_str()) > -2147483648)
			return 42;
		return 1;
	}
}
