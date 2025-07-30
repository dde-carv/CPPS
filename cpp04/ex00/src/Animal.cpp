#include "Animal.hpp"

Animal::Animal() : _type("animal")
{
	std::cout << GREEN << "Animal default constructor called." << RST << std::endl;
}

Animal::Animal(const Animal &object)
{
	*this = object;
	std::cout << GREEN << "Animal copy constructor called" << RST << std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "Animal default destructor called." << RST << std::endl;
}

void	Animal::setType(std::string type)
{
	_type = type;
}

std::string	Animal::getType() const
{
	return _type;
}

Animal	&Animal::operator=(const Animal &copy)
{
	if(this != &copy)
	{
		if(this->_type != copy._type)
			_type = copy._type;
	}
	std::cout << YELLOW << "Animal copy assignment operator called" << RST << std::endl;

	return *this;
}

void	Animal::makeSound() const
{
	std::cout << PURPLE << "Animal sound!" << RST << std::endl;
}