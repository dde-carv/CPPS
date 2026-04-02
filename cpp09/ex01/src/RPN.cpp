/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:16:21 by dde-carv          #+#    #+#             */
/*   Updated: 2025/11/18 16:19:09 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &src)
{
	(void)src;
}

RPN	&RPN::operator=(const RPN &src)
{
	(void)src;
	return *this;
}

RPN::~RPN()
{}

int	RPN::eval(const std::string &expr) const
{
	std::string			token;
	std::stack<int>		stack;
	std::istringstream	iss(expr);

	while (iss >> token)
	{
		if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
		{
			stack.push(token[0] - '0');
			continue ;
		}
		if (token != "+" && token != "-" && token != "*" && token != "/")
			throw std::runtime_error("Error: invalid member in expression!");
		if (stack.size() < 2)
			throw std::runtime_error("Error: there is not enough members!");

		int		b = stack.top(); stack.pop();
		int		a = stack.top(); stack.pop();
		long	r;

		switch (token[0])
		{
			case '+': r = (long)a + b; break ;
			case '-': r = (long)a - b; break ;
			case '*': r = (long)a * b; break ;
			case '/':
				if (b == 0)
					throw std::runtime_error("Error: in division 2nd number cannot be 0!");
				r = (long)a / b;
				break ;
			default:
				throw std::runtime_error("Error: unknown operator!");
		}
		if (r > INT_MAX || r < INT_MIN)
			throw std::runtime_error("Error: integer overflow!");
		stack.push(static_cast<int>(r));
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: there is no final result for the expression!");

	return stack.top();
}
