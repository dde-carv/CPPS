/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:31 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 10:39:32 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/************ Constructors and Destructor ************/

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(/* Add parameters here */)
{
	std::cout << "Custom constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		// Copy attributes here
	}
	std::cout << "Copy assignment operator called." << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called." << std::endl;
}
