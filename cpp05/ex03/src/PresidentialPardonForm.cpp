/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:24 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/13 10:17:53 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

/************ Constructors and Destructor ************/

PresidentialPardonForm::PresidentialPardonForm()
 : AForm("PresidentialPardonForm", "Default", 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm default constructor called." << RST << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
 : AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm custom constructor called." << RST << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
 : AForm(other)
{
	std::cout << GREEN << "PresidentialPardonForm copy constructor called." << RST << std::endl;

	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		AForm::operator=(other);

	std::cout << YELLOW << "PresidentialPardonForm copy assignment operator called." << RST << std::endl;

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destructor called." << RST << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << BLUE << "* As the sun rises, horns start to sing *" << RST << std::endl;
	std::cout << BLUE << "* In the mist of the sunrise, the Bureaucrat " << executor.getName() \
	 << " appears and begins to read a decree *" << RST << std::endl;
	std::cout << BLUE << "* \"In the name of the great Zaphod Beeblebrox, " << _target \
	 << " has been pardoned of all their actions!\" *" << RST << std::endl;
}
