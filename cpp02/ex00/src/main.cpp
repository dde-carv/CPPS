/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:00:05 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 16:42:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << "---------- Before setRawBits: ----------" << RST << std::endl;
	std::cout << a.getRawBits() << RST << std::endl;
	std::cout << b.getRawBits() << RST << std::endl;
	std::cout << c.getRawBits() << RST << std::endl;

	a.setRawBits(42);
	b.setRawBits(42);
	c.setRawBits(42);

	std::cout << RST << std::endl << "---------- After setRawBits: ----------" << RST << std::endl;
	std::cout << a.getRawBits() << RST << std::endl;
	std::cout << b.getRawBits() << RST << std::endl;
	std::cout << c.getRawBits() << RST << std::endl;

	return 0;
}
