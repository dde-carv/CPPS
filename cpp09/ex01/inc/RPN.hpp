/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:16:16 by dde-carv          #+#    #+#             */
/*   Updated: 2026/02/18 16:33:24 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <sstream>
#include <iostream>

class RPN
{
	private:
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);

	public:
		RPN();
		~RPN();

		int	eval(const std::string &expression) const;
};
