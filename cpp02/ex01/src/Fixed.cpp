#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

/************ Constructors and Destructor ************/

Fixed::Fixed() : _fixedPointVal(0)
{
	std::cout << GREEN << "Default constructor called" << RST << std::endl;
}

Fixed::Fixed(const int fixedPointVal) : _fixedPointVal(fixedPointVal << _fractionalBits)
{
	std::cout << GREEN << "Int constructor called" << RST << std::endl;
}

Fixed::Fixed(const float floatPointVal) : _fixedPointVal(roundf(floatPointVal * (1 << _fractionalBits)))
{
	std::cout << GREEN << "Float constructor called" << RST << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << YELLOW << "Copy constructor called" << RST << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << RED << "Default desconstructor called" << RST << std::endl;
}

/************ Operators ************/

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << YELLOW << "Copy assignment operator called" << RST << std::endl;
	_fixedPointVal = copy._fixedPointVal;
	return *this;
}

Fixed	&Fixed::operator++()
{
}

Fixed	Fixed::operator++(int)
{
}

Fixed	&Fixed::operator--()
{
}

Fixed	Fixed::operator--(int)
{
}


float	Fixed::operator+(const Fixed &copy)const
{
}

float	Fixed::operator-(const Fixed &copy)const
{
}

float	Fixed::operator*(const Fixed &copy)const
{
}

float	Fixed::operator/(const Fixed &copy)const
{
}


bool	Fixed::operator>(const Fixed &copy)const
{
}

bool	Fixed::operator<(const Fixed &copy)const
{
}

bool	Fixed::operator>=(const Fixed &copy)const
{
}

bool	Fixed::operator<=(const Fixed &copy)const
{
}

bool	Fixed::operator==(const Fixed &copy)const
{
}

bool	Fixed::operator!=(const Fixed &copy)const
{
}


std::ostream	&operator<<(std::ostream &stream, const Fixed &numb)
{
	stream << numb.toFloat();
	return stream;
}

/************ Getters and Setters ************/

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
}

Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
}

Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
}
