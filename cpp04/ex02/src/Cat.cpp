#include "../inc/Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << GREEN << "Cat default constructor called." << RST << std::endl;
}

Cat::Cat(const Cat &object)
{
	_brain = new Brain();
	*this = object;
	std::cout << GREEN << "Cat copy constructor called" << RST << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << RED << "Cat default destructor called." << RST << std::endl;
}

Cat	&Cat::operator=(const Cat &copy)
{
	if(this != &copy)
	{
		delete _brain;
		_brain = new Brain(*(copy._brain));
		if(this->_type != copy._type)
			_type = copy._type;
	}
	std::cout << YELLOW << "Cat copy assignment operator called" << RST << std::endl;

	return *this;
}

Brain	*Cat::getCatBrain()const
{
	return _brain;
}

std::string	Cat::getIdea(int i)const
{
	return _brain->getIdea(i);
}

void	Cat::setIdea(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}

void	Cat::printCatIdeas(int limit)const
{
	_brain->printIdeas(limit);
}

void	Cat::makeSound() const
{
	std::cout << PURPLE << "MeeeeEEEEeeeEEeeOOooooOW!" << RST << std::endl;
}