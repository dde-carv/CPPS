/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:07:30 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 16:42:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

/************ Constructors and Destructor ************/

Form::Form() : _name("Form"), _gradeToSign(150), _gradeToExec(150), _signed(false)
{
	std::cout << GREEN << "Form default constructor called" << RST << std::endl;
}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExec)
 : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	std::cout << GREEN << "Form custom constructor called" << RST << std::endl;

	try
	{
		if (_gradeToSign > 150 || _gradeToExec > 150)
			throw GradeTooLowException();
		if (_gradeToSign < 1 || _gradeToExec < 1)
			throw GradeTooHighException();
		std::cout << GREEN << "Form " << _name << " has valid grades, accepted!" << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Form constructor exception (" << _name << "): "\
		 << e.what() << RST << std::endl;
	}
}

Form::Form(const Form &other)
 : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << GREEN << "Form copy constructor called" << RST << std::endl;

	*this = other;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;

	std::cout << YELLOW << "Form copy assignment operator called" << RST << std::endl;

	return *this;
}

Form::~Form()
{
	std::cout << RED << "Form default destructor called" << RST << std::endl;
}

/************ Getters ************/

std::string	Form::getName() const
{
	return _name;
}

int			Form::getGradeToSign() const
{
	return _gradeToSign;
}

int			Form::getGradeToExec() const
{
	return _gradeToExec;
}

bool		Form::getSigned() const
{
	return _signed;
}

/************ Member Function ************/

int			Form::beSigned(const Bureaucrat &bur)
{
	try
	{
		if (getSigned() == true)
			return PREVIOUSLY_SIGNED;
		if (bur.getGrade() <= getGradeToSign())
		{
			_signed = true;
			return SIGNED;
		}
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "beSigned exeption: " << e.what() << RST << std::endl;
		return NOT_SIGNED;
	}
}

/************ Execeptions ************/

const char* Form::GradeTooHighException::what() const throw()
{
	return "the Form grade is too high!!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "the Form grade is too low!!";
}

/************ Other ************/

std::ostream	&operator<<(std::ostream &stream, const Form &object)
{
	stream << object.getName() << ", bureaucrat expected grade to sign is " << object.getGradeToSign() \
	 << " and grade to execute is " << object.getGradeToExec() << "." << RST << std::endl;
	return stream;
}
