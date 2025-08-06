#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << GREEN << "Dog default constructor called." << RST << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << GREEN << "Dog costum constructor called." << RST << std::endl;
}

Dog::Dog(const Dog &object) : Animal(object)
{
	std::cout << GREEN << "Dog copy constructor called" << RST << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog default destructor called." << RST << std::endl;
}

Dog	&Dog::operator=(const Dog &copy)
{
	if(this != &copy)
		Animal::operator=(copy);

	std::cout << YELLOW << "Dog copy assignment operator called" << RST << std::endl;

	return *this;
}

void	Dog::makeSound() const
{
	std::cout << PURPLE << "WOOOOF WOOFF WOOOOOOOOF..." << RST << std::endl;
}
