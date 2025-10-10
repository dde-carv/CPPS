/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:28 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 13:58:12 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/************ Constructors and Destructor ************/

RobotomyRequestForm::RobotomyRequestForm()
 : AForm("Default", "Default", 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called." << std::endl << RST;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
 : AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm custom constructor called." << std::endl << RST;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
 : AForm(other)
{
	std::cout << GREEN << "RobotomyRequestForm copy constructor called." << std::endl << RST;

	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);

	std::cout << YELLOW << "RobotomyRequestForm copy assignment operator called." << std::endl << RST;

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called." << std::endl << RST;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << BLUE << "* BRZBRZBRZBRZBRZ * - Drilling noises!!" << std::endl << RST;
	if (std::rand() % 2)
		std::cout << BLUE << _target << " has been robotomized sucessfully by " \
		 << executor.getName() << "!" << std::endl << RST;
	else
		std::cout << BLUE << _target << " failed the robotomy by " \
		 << executor.getName() << "!" << std::endl << RST;
}
