/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:16:18 by dde-carv          #+#    #+#             */
/*   Updated: 2026/02/18 16:33:32 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error("Error: invalid number of arguments!");

		RPN	calcuator;
		int	result = calcuator.eval(av[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
