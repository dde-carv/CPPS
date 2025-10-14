/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:28 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/14 11:33:22 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

/************ Constructors and Destructor ************/

RobotomyRequestForm::RobotomyRequestForm()
 : AForm("RobotomyRequestForm", "Default", 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called." << RST << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
 : AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm custom constructor called." << RST << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
 : AForm(other)
{
	std::cout << GREEN << "RobotomyRequestForm copy constructor called." << RST << std::endl;

	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);

	std::cout << YELLOW << "RobotomyRequestForm copy assignment operator called." << RST << std::endl;

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called." << RST << std::endl;
}

void	RobotomyRequestForm::action(Bureaucrat const &executor) const
{
	std::cout << BLUE << "* BRZBRZBRZBRZBRZ * - Drilling noises!!" << RST << std::endl;
	if (std::rand() % 2)
		std::cout << _target << GREEN << " has been robotomized sucessfully by " \
		 << executor.getName() << "!" << RST << std::endl;
	else
		std::cout << _target << RED << " failed the robotomy by " \
		 << executor.getName() << "!" << RST << std::endl;
}
