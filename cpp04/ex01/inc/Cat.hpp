#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &object);
		virtual ~Cat();

		Cat			&operator=(const Cat &copy);

		Brain		*getCatBrain()const;
		std::string	getCatIdea(int i)const;

		void		setCatIdea(int i, std::string idea);

		virtual void		makeSound()const;
		void		printCatIdeas(int limit)const;
};
