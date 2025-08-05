#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const Cat &object);
		~Cat();

		Cat			&operator=(const Cat &copy);

		Brain		*getCatBrain()const;
		std::string	getCatIdea(int i)const;

		void		setCatIdea(int i, std::string idea);

		void		makeSound()const;
		void		printCatIdeas(int limit)const;
};
