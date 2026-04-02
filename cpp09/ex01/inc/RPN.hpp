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
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <climits>

class RPN
{
	private:
		RPN(const RPN &src);
		RPN	&operator=(const RPN &src);

	public:
		RPN();
		~RPN();

		int	eval(const std::string &expr) const;
};
