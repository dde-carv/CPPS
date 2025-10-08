/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:01 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/08 17:45:11 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;

		AForm();
		AForm(const std::string &name, const int &gradeToSign, const int &gradeToExec);
		AForm(const AForm &other);

	public:
		AForm	&operator=(const AForm &other);
		virtual	~AForm() = 0;

		std::string	getName() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		bool		getSigned() const;

		void		beSigned(const Bureaucrat &bur);
		void		checkExecute(const Bureaucrat &executor) const;
		virtual void	execute(const Bureaucrat &executor) = 0;


	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class	AlreadySignedException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	NotSignedException: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, const Form &object);
