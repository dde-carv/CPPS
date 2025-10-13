/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:07:27 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/13 10:17:20 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

/************ Constructors and Destructor ************/

Bureaucrat::Bureaucrat() : _name("Leclerc"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RST << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << GREEN << "Bureaucrat custom constructor called" << RST << std::endl;

	try
	{
		if (_grade < 1)
			throw GradeTooHighException();
		if (_grade > 150)
			throw GradeTooLowException();
		std::cout << GREEN << "Bureaucrat " << _name << " has a valid grade -> "\
		 << _grade << ", accepted!" << RST << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << RED << "Bureaucrat constructor exception (" << _name << "): "\
		 << e.what() << RST << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	std::cout << GREEN << "Bureaucrat copy constructor called" << RST << std::endl;

	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;

	std::cout << YELLOW << "Bureaucrat copy assignment operator called" << RST << std::endl;

	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat default destructor called" << RST << std::endl;
}

/************ Getters ************/

const std::string	Bureaucrat::getName() const
{
	return _name;
}

int					Bureaucrat::getGrade() const
{
	return _grade;
}

/************ Member Functions ************/

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade == 1)
			throw GradeTooHighException();
		_grade--;
		std::cout << PURPLE << "Grade Incremented -> " << *this << RST;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Grade incrementing exception (" << _name << "): "\
		 << e.what() << RST << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade == 150)
			throw GradeTooLowException();
		_grade++;
		std::cout << YELLOW << "Grade Decremented -> " << *this << RST;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Grade decrementing exception (" << _name << "): " \
		 << e.what() << RST << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << BLUE << "The Bureaucrat " << _name << " signed " \
		 << form.getName() << "." << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception: the Bureaucrat " << _name \
		 << " couldn't sign " << form.getName() << " because " \
		 << e.what() << RST << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.checkExecute(*this);
		form.execute(*this);
		std::cout << BLUE << "The Bureaucrat " << _name << " executed " \
		 << form.getName() << "." << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception: The Bureaucrat " << _name \
		 << " couldn't execute " << form.getName() << " because " \
		 << e.what() << RST << std::endl;
	}
}

/************ Execeptions ************/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the Bureaucrat grade is too high!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the Bureaucrat grade is too low!!";
}

/************ Other ************/

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade() << "." << RST << std::endl;
	return stream;
}
