#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &object);
		virtual ~Dog();

		Dog			&operator=(const Dog &copy);

		Brain		*getDogBrain()const;
		std::string	getDogIdea(int i)const;

		void		setDogIdea(int i, std::string idea);

		virtual void	makeSound() const;
		void			printDogIdeas(int limit)const;
};
