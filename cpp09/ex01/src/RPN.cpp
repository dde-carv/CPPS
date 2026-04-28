/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:16:21 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/28 16:11:01 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &other) : _operands(other._operands)
{}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_operands = other._operands;
	return *this;
}

RPN::~RPN()
{}

bool	RPN::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int	RPN::applyOp(char op, int left, int right) const
{
	switch (op)
	{
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			if (right == 0)
				throw std::runtime_error("division by zero");
			return left / right;
	}
	throw std::runtime_error("unknown operator");
}

int	RPN::resolve(const std::string &expr)
{
	std::istringstream	stream(expr);
	std::string			token;

	while (stream >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			_operands.push(token[0] - '0');
		else if (token.size() == 1 && isOperator(token[0]))
		{
			if (_operands.size() < 2)
				throw std::runtime_error("not enough operands");
			int	right = _operands.top();
			_operands.pop();
			int	left = _operands.top();
			_operands.pop();
			_operands.push(applyOp(token[0], left, right));
		}
		else
			throw std::runtime_error("invalid token: " + token);
	}

	if (_operands.size() != 1)
		throw std::runtime_error("invalid expression");
	return _operands.top();
}
