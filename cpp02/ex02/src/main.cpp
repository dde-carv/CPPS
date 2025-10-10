/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:00:40 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 16:42:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	std::cout << "==================== TEST 1 ====================" << RST << std::endl << RST << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << RST << std::endl;
	std::cout << ++a << RST << std::endl;
	std::cout << a << RST << std::endl;
	std::cout << a++ << RST << std::endl;
	std::cout << a << RST << std::endl;

	std::cout << b << RST << std::endl;

	std::cout << Fixed::max( a, b ) << RST << std::endl;

	std::cout << RST << std::endl << "==================== TEST 2 ====================" << RST << std::endl << RST << std::endl;

	float	left = 5.05;
	float	right = 2.5;

	Fixed const n1(Fixed(left) + Fixed(right));
	Fixed const n2(Fixed(left) - Fixed(right));
	Fixed const n3(Fixed(left) * Fixed(right));
	Fixed const n4(Fixed(left) / Fixed(right));

	std::cout << n1 << RST << std::endl;
	std::cout << n2 << RST << std::endl;
	std::cout << n3 << RST << std::endl;
	std::cout << n4 << RST << std::endl;

	std::cout << RST << std::endl << "==================== TEST 3 ====================" << RST << std::endl << RST << std::endl;

	Fixed	x;
	Fixed	limit;

	limit.setRawBits(2);
	x.setRawBits(0);
	std::cout << "--- PRE-ICREMENT OVERLOAD ---" << RST << std::endl;
	while (++x < limit)
		std::cout << "x = " << x << " & limit = " << limit << RST << std::endl;

	x.setRawBits(0);
	std::cout << RST << std::endl << "--- POST-ICREMENT OVERLOAD ---" << RST << std::endl;
	while (x++ < limit)
		std::cout << "x = " << x << " & limit = " << limit << RST << std::endl;

	limit.setRawBits(0);
	x.setRawBits(2);
	std::cout << RST << std::endl << "--- PRE-DECREMENT OVERLOAD ---" << RST << std::endl;
	while (--x > limit)
		std::cout << "x = " << x << " & limit = " << limit << RST << std::endl;

	x.setRawBits(2);
	std::cout << RST << std::endl << "--- POST-DECREMENT OVERLOAD ---" << RST << std::endl;
	while (x-- > limit)
		std::cout << "x = " << x << " & limit = " << limit << RST << std::endl;

	std::cout << RST << std::endl << "==================== TEST 4 ====================" << RST << std::endl << RST << std::endl;

	Fixed const &a1(1);
	Fixed const	&a2(2);
	Fixed		b1(3);
	Fixed		b2(4);

	std::cout << Fixed::max(a1, a2) << RST << std::endl;
	std::cout << Fixed::max(b1, b2) << RST << std::endl;
	std::cout << Fixed::min(a1, a2) << RST << std::endl;
	std::cout << Fixed::min(b1, b2) << RST << std::endl;

	std::cout << RST << std::endl << "==================== TEST 5 ====================" << RST << std::endl << RST << std::endl;

	Fixed	y1(1);
	Fixed	x1(1);
	Fixed	y2(2);
	Fixed	x2(2);

	if (y2 > y1)
		std::cout << "y2 > y1" << RST << std::endl;
	if (y1 < y2)
		std::cout << "y1 < y2" << RST << std::endl;
	if ((y1 >= x1) && (y2 >= y1))
		std::cout << "(y1 >= x1) && (y2 >= y1)" << RST << std::endl;
	if ((y1 <= x1) && (y1 <= y1))
		std::cout << "(y1 <= x1) && (y1 <= y2)" << RST << std::endl;
	if (x1 == y1)
		std::cout << "x1 == y1" << RST << std::endl;
	if (x1 != x2)
		std::cout << "x1 != x2" << RST << std::endl << RST << std::endl;

	return 0;
}
