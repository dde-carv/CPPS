#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog(const Dog &object);
		~Dog();

		Dog			&operator=(const Dog &copy);

		Brain		*getDogBrain()const;
		std::string	getDogIdea(int i)const;

		void		setDogIdea(int i, std::string idea);

		void		makeSound()const;
		void		printDogIdeas(int limit)const;
};
