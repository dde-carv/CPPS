/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:01 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/13 15:37:12 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		std::string			_target;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;

		AForm();
		AForm(const std::string &name, std::string target, const int &gradeToSign, const int &gradeToExec);
		AForm(const AForm &other);

	public:
		AForm	&operator=(const AForm &other);
		virtual	~AForm() = 0;

		std::string		getName() const;
		int				getGradeToSign() const;
		int				getGradeToExec() const;
		bool			getSigned() const;

		void			beSigned(const Bureaucrat &bur);
		void			execute(const Bureaucrat &executor) const;
		virtual void	action(const Bureaucrat &executor) const = 0;


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

std::ostream	&operator<<(std::ostream &stream, const AForm &object);
