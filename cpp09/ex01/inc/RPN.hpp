/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:16:16 by dde-carv          #+#    #+#             */
/*   Updated: 2026/01/28 10:35:35 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <sstream>
#include <iostream>

class RPN
{
	public:
		RPN();
		~RPN();

		int	eval(const std::string &expression) const;

	private:
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
};
