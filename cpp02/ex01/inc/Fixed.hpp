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
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		float	operator+(const Fixed &copy)const;
		float	operator-(const Fixed &copy)const;
		float	operator*(const Fixed &copy)const;
		float	operator/(const Fixed &copy)const;

		bool	operator>(const Fixed &copy)const;
		bool	operator<(const Fixed &copy)const;
		bool	operator>=(const Fixed &copy)const;
		bool	operator<=(const Fixed &copy)const;
		bool	operator==(const Fixed &copy)const;
		bool	operator!=(const Fixed &copy)const;

		int		getRawBits()const;
		void	setRawBits(int const raw);

		float	toFloat(void)const;
		int		toInt(void)const;

		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &numb);
