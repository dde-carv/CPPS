#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &object);
		~Dog();

		Dog		&operator=(const Dog &copy);

		void	makeSound() const;
};
