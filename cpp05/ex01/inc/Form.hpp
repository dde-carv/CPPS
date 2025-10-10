/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:07:24 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 11:32:57 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define NOT_SIGNED 0
#define SIGNED 1
#define PREVIOUSLY_SIGNED 2

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;

	public:
		Form();
		Form(const std::string &name, const int &gradeToSign, const int &gradeToExec);
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();

		std::string	getName() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		bool		getSigned() const;

		int			beSigned(const Bureaucrat &bur);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, const Form &object);
