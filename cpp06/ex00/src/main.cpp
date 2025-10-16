/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:56:40 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/16 12:03:04 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Wrong number of arguments!" << RST << std::endl;
		return 1;
	}
	std::cout << av[1] << std::endl;
	ScalarConverter::convert(av[1]);
	return 0;
}
