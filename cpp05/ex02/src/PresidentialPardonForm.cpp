/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:24 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 13:45:06 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/************ Constructors and Destructor ************/

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(/* Add parameters here */)
{
	std::cout << "Custom constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		// Copy attributes here
	}
	std::cout << "Copy assignment operator called." << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called." << std::endl;
}
