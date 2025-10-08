/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:28 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 10:39:29 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/************ Constructors and Destructor ************/

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(/* Add parameters here */)
{
	std::cout << "Custom constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		// Copy attributes here
	}
	std::cout << "Copy assignment operator called." << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called." << std::endl;
}
