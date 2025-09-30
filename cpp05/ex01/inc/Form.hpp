/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:07:24 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/30 11:22:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

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

		const std::string	getName() const;
		const int			getGradeToSign() const;
		const int			getGradeToExec() const;
		bool				getSigned() const;

		void				beSigned(const Bureaucrat &bur);

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
