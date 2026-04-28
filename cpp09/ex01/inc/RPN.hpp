/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:16:16 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/28 16:10:05 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		~RPN();

		int	resolve(const std::string &expr);

	private:
		std::stack<int>	_operands;

		bool	isOperator(char c) const;
		int		applyOp(char op, int left, int right) const;
};
