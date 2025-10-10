/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:00:21 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 16:42:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << RST << std::endl;
	std::cout << "b is " << b << RST << std::endl;
	std::cout << "c is " << c << RST << std::endl;
	std::cout << "d is " << d << RST << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << RST << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << RST << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << RST << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << RST << std::endl;

	return 0;
}
