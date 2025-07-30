#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << GREEN << "Cat default constructor called." << RST << std::endl;
}

Cat::Cat(const Cat &object)
{
	*this = object;
	std::cout << GREEN << "Cat copy constructor called" << RST << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat default destructor called." << RST << std::endl;
}

Cat	&Cat::operator=(const Cat &copy)
{
	if(this != &copy)
	{
		if(this->_type != copy._type)
			_type = copy._type;
	}
	std::cout << YELLOW << "Cat copy assignment operator called" << RST << std::endl;

	return *this;
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "MeeeeEEEEeeeEEeeOOooooOW!" << RST << std::endl;
}