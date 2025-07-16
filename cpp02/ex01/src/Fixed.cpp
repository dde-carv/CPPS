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

std::ostream	&operator<<(std::ostream &stream, const Fixed &numb)
{
	stream << numb.toFloat();
	return stream;
}

/************ Getters ************/

int	Fixed::getRawBits()const
{
	std::cout << GREEN << "getRawBits function called" << RST << std::endl;
	return _fixedPointVal;
}

/************ Setters ************/

void	Fixed::setRawBits(int const raw)
{
	std::cout << GREEN << "setRawBits function called" << RST << std::endl;
	_fixedPointVal = raw;
}

/************ Others ************/

float	toFloat(void)const
{
	
}
