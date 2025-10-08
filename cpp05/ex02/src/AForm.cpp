/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:20 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 17:52:43 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/************ Constructors and Destructor ************/

AForm::AForm() : _name("AForm"), _gradeToSign(150), _gradeToExec(150), _signed(false)
{
	std::cout << GREEN << "AForm default constructor called" << std::endl << RST;
}

AForm::AForm(const std::string &name, const int &gradeToSign, const int &gradeToExec)
 : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	std::cout << GREEN << "AForm custom constructor called" << std::endl << RST;

	try
	{
		if (_gradeToSign > 150 || _gradeToExec > 150)
			throw GradeTooLowException();
		if (_gradeToSign < 1 || _gradeToExec < 1)
			throw GradeTooHighException();
		std::cout << "AForm " << _name << " has valid grades, accepted!" << std::endl << RST;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "AForm constructor exception (" << _name << "): "\
		 << e.what() << std::endl << RST;
	}
}

AForm::AForm(const AForm &other)
 : _name(other._name), _gradeToSign(other._gradeToSign), \
 _gradeToExec(other._gradeToExec), _signed(other._signed)
{
	std::cout << GREEN << "AForm copy constructor called" << std::endl << RST;
}

AForm::~AForm()
{
	std::cout << GREEN << "AForm default destructor called" << std::endl << RST;
}

/************ Getters ************/

std::string	AForm::getName() const
{
	return _name;
}

int			AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int			AForm::getGradeToExec() const
{
	return _gradeToExec;
}

bool		AForm::getSigned() const
{
	return _signed;
}

/************ Member Function ************/

void		AForm::beSigned(const Bureaucrat &bur)
{
	if (getSigned() == true)
		throw AlreadySignedException();
	if (bur.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_signed = true;
}

void		AForm::checkExecute(const Bureaucrat &executor) const
{
	if (getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
}

/************ Execeptions ************/

const char* AForm::GradeTooHighException::what() const throw()
{
	return "the form grade is too high!!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "the form grade is too low!!";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "the form has already been signed by someone!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "the form is not signed, do it first before trying to execute it!";
}

/************ Operators ************/

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;

	std::cout << GREEN << "AForm copy assignment operator called" << std::endl << RST;

	return *this;
}

std::ostream	&operator<<(std::ostream &stream, const AForm &object)
{
	stream << object.getName() << ", bureaucrat expected grade to sign is " << object.getGradeToSign() \
	<< " and grade to execute is " << object.getGradeToExec() << "." << std::endl;
	return stream;
}
