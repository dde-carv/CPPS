#pragma once

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RST "\033[0m"

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedPointVal;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(const int fixedPointVal);
		Fixed(const float floatPointVal);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed	&operator=(const Fixed &copy);
		int		getRawBits()const;
		void	setRawBits(int const raw);
		float	toFloat(void)const;
		int		toInt(void)const;
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &numb);
