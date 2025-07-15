#pragma once

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RST "\033[0m"

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointVal;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &copy);
		~Fixed();
		int		getRawBits()const;
		void	setRawBits(int const raw);
};
