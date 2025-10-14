/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:17:24 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/14 16:31:32 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

/************ Constructors and Destructor ************/

Intern::Intern()
{
	std::cout << GREEN << "Intern default constructor called." << RST << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << GREEN << "Intern copy constructor called." << RST << std::endl;

	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;

	std::cout << YELLOW << "Intern copy assignment operator called." << RST << std::endl;

	return *this;
}

Intern::~Intern()
{
	std::cout << RED << "Intern destructor called." << RST << std::endl;
}

/************ Member Functions ************/

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string formName[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (name == formName[i])
		{
			AForm *form = NULL;
			switch (i)
			{
				case 0:
					form = new PresidentialPardonForm(target);
					break;
				case 1:
					form = new RobotomyRequestForm(target);
					break;
				case 2:
					form = new ShrubberyCreationForm(target);
					break;
				default:
					throw InvalidName();
			}
			std::cout << BLUE << "Intern creates " << name << " form." << RST << std::endl;
			return form;
		}
	}
	throw InvalidName();
}

/************ Execeptions ************/

const char* Intern::InvalidName::what() const throw()
{
	return "the name of the form does not exist!!";
}
