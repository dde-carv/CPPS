#include "../inc/Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << GREEN << "Dog default constructor called." << RST << std::endl;
}

Dog::Dog(const Dog &object)
{
	_brain = new Brain();
	*this = object;
	std::cout << GREEN << "Dog copy constructor called" << RST << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << RED << "Dog default destructor called." << RST << std::endl;
}

Dog	&Dog::operator=(const Dog &copy)
{
	if(this != &copy)
	{
		delete _brain;
		_brain = new Brain(*(copy._brain));
		if(this->_type != copy._type)
			_type = copy._type;
	}
	std::cout << YELLOW << "Dog copy assignment operator called" << RST << std::endl;

	return *this;
}

Brain	*Dog::getDogBrain()const
{
	return _brain;
}

std::string	Dog::getIdea(int i)const
{
	return _brain->getIdea(i);
}

void	Dog::setIdea(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}

void	Dog::printDogIdeas(int limit)const
{
	_brain->printIdeas(limit);
}

void	Dog::makeSound() const
{
	std::cout << PURPLE << "WOOOOF WOOFF WOOOOOOOOF..." << RST << std::endl;
}