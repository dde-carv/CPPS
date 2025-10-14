/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:43:41 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/14 16:21:10 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

AForm*	Intern_exception(AForm* form, Bureaucrat &bur,\
 const std::string formName, const std::string target)
{
	Intern	someRandomIntern;

	try
	{
		form = someRandomIntern.makeForm(formName, target);
		bur.executeForm(*form);
		bur.signForm(*form);
		bur.executeForm(*form);
		return form;
	}
	catch(std::exception &e)
	{
		std::cout << RED << "Exception: the intern realized that " \
		 << e.what() << RST << std::endl;
	}
	return NULL;
}

void	Intern_test(Bureaucrat &good, Bureaucrat &bad)
{
	std::cout << "\n----- Intern Test -----\n\n";
	AForm*	blah = NULL;
	AForm*	bruh = NULL;
	AForm*	rrf = NULL;

	blah = Intern_exception(blah, good, "blah", "the Universe");
	bruh = Intern_exception(bruh, bad, "Bruh", "the Universe");
	rrf = Intern_exception(rrf, good, "robotomy request", "Bender");

	if (blah)
		delete blah;
	if (bruh)
		delete bruh;
	if (rrf)
		delete rrf;
}

void	ShrubberyCreationForm_test(Bureaucrat &good, Bureaucrat &bad)
{
	std::cout << "\n----- Shrubbery Creation Form -----\n\n";

	ShrubberyCreationForm	form("Churrasqueira");
	bad.signForm(form);
	good.executeForm(form);
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
	bad.executeForm(form);
	good.executeForm(form);
}

int main()
{
	Bureaucrat	Alberto("Alberto", 1);
	Bureaucrat	Ulisses("Ulisses", 150);
	//AForm		RandomForm;
	std::cout << "\n\n----- Initial values -----\n\n";
	std::cout << Alberto;
	std::cout << Ulisses;

	Alberto.incrementGrade();
	Ulisses.decrementGrade();

	Intern_test(Alberto, Ulisses);
	ShrubberyCreationForm_test(Alberto, Ulisses);
	RobotomyRequestForm_test(Alberto, Ulisses);
	PresidentialPardonForm_test(Alberto, Ulisses);
	return 0;
}
