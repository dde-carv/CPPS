#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "I'm hungry!";
	std::cout << GREEN << "Brain default constructor called." << RST << std::endl;
}

Brain::Brain(const Brain &object)
{
	*this = object;
	std::cout << GREEN << "Brain copy constructor called." << RST << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Brain default destructor called." << RST << std::endl;
}

Brain	&Brain::operator=(const Brain &copy)
{
	if(this != &copy)
	{
		for(int i = 0; i < 100; i++)
		{
			if (this->_ideas[i] != copy._ideas[i])
				_ideas[i] = copy._ideas[i];
		}
	}
	std::cout << YELLOW << "Brain copy assignment operator called." << RST << std::endl;

	return *this;
}

std::string	Brain::getIdea(int i)const
{
	if (i >= 0 && i < 100)
		return (_ideas[i]);
	return (NULL);
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i >= 0 && i < 100)
		_ideas[i] = idea;
}

void	Brain::printIdeas(int limit)const
{
	for (int i = 0; i < 100 && i < limit; i++)
		std::cout << PURPLE << i << ": \"" << _ideas[i] << "\"" << RST << std::endl;
}
