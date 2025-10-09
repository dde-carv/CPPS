/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:24 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/09 10:41:56 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/************ Constructors and Destructor ************/

PresidentialPardonForm::PresidentialPardonForm()
 : AForm("Default", "Default", 25, 5)
{
	std::cout << GREEN << "Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
 : AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << GREEN << "Custom constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
 : AForm(other._name, other._target, other._gradeToSign, other._gradeToExec)
{
	std::cout << GREEN << "Copy constructor called." << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		_signed = other._signed;
	std::cout << YELLOW << "Copy assignment operator called." << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "Destructor called." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	std::cout << BLUE << "* As the sun rises, horns start to sing *" << std::endl << RST;
	std::cout << BLUE << "* In the mist of the sunrise, the Bureaucrat " << executor.getName() \
	 << " appears and begins to read a decree *" << std::endl << RST;
	std::cout << BLUE << "* \"In the name of the great Zaphod Beeblebrox, " << _target \
	 << " has been pardoned of all their actions!\" *" << std::endl << RST;
}