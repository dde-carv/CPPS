#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << GREEN << "Default constructor called" << RST << std::endl;
	_fixedPointVal = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << YELLOW << "Copy constructor called" << RST << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << YELLOW << "Copy assignment operator called" << RST << std::endl;
	if(this != &copy)
		_fixedPointVal = copy._fixedPointVal;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << RED << "Default desconstructor called" << RST << std::endl;
}

int	Fixed::getRawBits()const
{
	std::cout << GREEN << "getRawBits function called" << RST << std::endl;
	return _fixedPointVal;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << GREEN << "setRawBits function called" << RST << std::endl;
	_fixedPointVal = raw;
}
