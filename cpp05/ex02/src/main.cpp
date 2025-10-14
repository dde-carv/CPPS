/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:43:41 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/14 11:41:40 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

void	ShrubberyCreationForm_test(Bureaucrat &good, Bureaucrat &bad)
{
	std::cout << "\n----- Shrubbery Creation Form -----\n\n";
	ShrubberyCreationForm	form("Churrasqueira");
	bad.signForm(form);
	good.executeForm(form);
	good.signForm(form);
	good.signForm(form);
	bad.executeForm(form);
	good.executeForm(form);
}

void	RobotomyRequestForm_test(Bureaucrat &good, Bureaucrat &bad)
{
	std::cout << "\n----- Robotomy Request Form -----\n\n";

	RobotomyRequestForm	form("Sheldon");
	bad.signForm(form);
	good.executeForm(form);
	good.signForm(form);
	good.signForm(form);
	bad.executeForm(form);
	good.executeForm(form);
	good.executeForm(form);
	good.executeForm(form);
}

void	PresidentialPardonForm_test(Bureaucrat &good, Bureaucrat &bad)
{
	std::cout << "\n----- Presidential Pardon Form -----\n\n";
	PresidentialPardonForm	form("Socrates");
	bad.signForm(form);
	good.executeForm(form);
	good.signForm(form);
	good.signForm(form);
	bad.executeForm(form);
	good.executeForm(form);
}

int main()
{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		Bureaucrat	Alberto("Alberto", 1);
		Bureaucrat	Ulisses("Ulisses", 150);
		//AForm RandomForm;
		std::cout << "\n----- Initial values -----\n\n";
		std::cout << Alberto;
		std::cout << Ulisses;

		Alberto.incrementGrade();
		Ulisses.decrementGrade();

		ShrubberyCreationForm_test(Alberto, Ulisses);
		RobotomyRequestForm_test(Alberto, Ulisses);
		PresidentialPardonForm_test(Alberto, Ulisses);
		return 0;
}
