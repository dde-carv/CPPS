#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << GREEN << "Dog default constructor called." << RST << std::endl;
}

Dog::Dog(const Dog &object)
{
	*this = object;
	std::cout << GREEN << "Dog copy constructor called" << RST << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog default destructor called." << RST << std::endl;
}

Dog	&Dog::operator=(const Dog &copy)
{
	if(this != &copy)
	{
		if(this->_type != copy._type)
			_type = copy._type;
	}
	std::cout << YELLOW << "Dog copy assignment operator called" << RST << std::endl;

	return *this;
}

void	Dog::makeSound() const
{
	std::cout << PURPLE << "WOOOOF WOOFF WOOOOOOOOF..." << RST << std::endl;
}