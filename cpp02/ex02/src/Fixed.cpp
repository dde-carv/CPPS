/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:00:36 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 17:00:37 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

/************ Constructors and Destructor ************/

Fixed::Fixed() : _fixedPointVal(0)
{
	//std::cout << GREEN << "Default constructor called" << RST << std::endl;
}

Fixed::Fixed(const int fixedPointVal) : _fixedPointVal(fixedPointVal << _fractionalBits)
{
	//std::cout << GREEN << "Int constructor called" << RST << std::endl;
}

Fixed::Fixed(const float floatPointVal) : _fixedPointVal(roundf(floatPointVal * (1 << _fractionalBits)))
{
	//std::cout << GREEN << "Float constructor called" << RST << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << YELLOW << "Copy constructor called" << RST << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	//std::cout << RED << "Default destructor called" << RST << std::endl;
}

/************ Operators ************/

Fixed	&Fixed::operator=(const Fixed &copy)
{
	//std::cout << YELLOW << "Copy assignment operator called" << RST << std::endl;
	if(this != &copy)
		_fixedPointVal = copy._fixedPointVal;
	return *this;
}

Fixed	&Fixed::operator++()
{
	_fixedPointVal++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	_fixedPointVal++;
	return tmp;
}

Fixed	&Fixed::operator--()
{
	_fixedPointVal--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	_fixedPointVal--;
	return tmp;
}


Fixed	Fixed::operator+(const Fixed &copy)const
{
	return Fixed(this->toFloat() + copy.toFloat());
}

Fixed	Fixed::operator-(const Fixed &copy)const
{
	return Fixed(this->toFloat() - copy.toFloat());
}

Fixed	Fixed::operator*(const Fixed &copy)const
{
	return Fixed(this->toFloat() * copy.toFloat());
}

Fixed	Fixed::operator/(const Fixed &copy)const
{
	return Fixed(this->toFloat() / copy.toFloat());
}


bool	Fixed::operator>(const Fixed &copy)const
{
	if (this->getRawBits() > copy.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed &copy)const
{
	if (this->getRawBits() < copy.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed &copy)const
{
	if (this->getRawBits() >= copy.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed &copy)const
{
	if (this->getRawBits() <= copy.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed &copy)const
{
	if (this->getRawBits() == copy.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed &copy)const
{
	if (this->getRawBits() != copy.getRawBits())
		return true;
	return false;
}


std::ostream	&operator<<(std::ostream &stream, const Fixed &numb)
{
	stream << numb.toFloat();
	return stream;
}

/************ Getters and Setters ************/

int	Fixed::getRawBits()const
{
	//std::cout << GREEN << "getRawBits function called" << RST << std::endl;
	return _fixedPointVal;
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << GREEN << "setRawBits function called" << RST << std::endl;
	_fixedPointVal = raw;
}

/************ Conversions ************/

float	Fixed::toFloat(void)const
{
	return (float)_fixedPointVal / (1 << _fractionalBits);
}

int	Fixed::toInt(void)const
{
	return _fixedPointVal >> _fractionalBits;
}

/************ Other ************/

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (Fixed&) a;
	return (Fixed&) b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (Fixed&) a;
	return (Fixed&) b;
}
