/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:20 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/15 09:58:41 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

/************ Constructors and Destructor ************/

AForm::AForm()
 : _name("Default"), _target("Default"), _gradeToSign(150), _gradeToExec(150), _signed(false)
{
	std::cout << GREEN << "AForm default constructor called." << RST << std::endl;
}

AForm::AForm(const std::string &name, std::string target, const int &gradeToSign, const int &gradeToExec)
 : _name(name), _target(target), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	std::cout << GREEN << "AForm custom constructor called." << RST << std::endl;

	try
	{
		if (_gradeToSign > 150 || _gradeToExec > 150)
			throw GradeTooLowException();
		if (_gradeToSign < 1 || _gradeToExec < 1)
			throw GradeTooHighException();
		std::cout << "AForm " << _name << " has valid grades, accepted!" << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "AForm constructor exception (" << _name << "): " \
		 << e.what() << RST << std::endl;
	}
}

AForm::AForm(const AForm &other)
 : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	std::cout << GREEN << "AForm copy constructor called." << RST << std::endl;

	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_target = other._target;
		_signed = other._signed;
	}

	std::cout << YELLOW << "AForm copy assignment operator called." << RST << std::endl;

	return *this;
}

AForm::~AForm()
{
	std::cout << RED << "AForm default destructor called." << RST << std::endl;
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
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
}

void		AForm::execute(const Bureaucrat &executor) const
{
	if (getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();
	action(executor);
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

/************ Other ************/

std::ostream	&operator<<(std::ostream &stream, const AForm &object)
{
	stream << object.getName() << ", bureaucrat expected grade to sign is " << object.getGradeToSign() \
	 << " and grade to execute is " << object.getGradeToExec() << "." << RST << std::endl;
	return stream;
}
