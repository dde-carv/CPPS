#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	test1()
{
	std::cout << "\n==========| TEST 1 |==========\n\n";

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void	test2()
{
	std::cout << "\n==========| TEST 2 |==========\n\n";

	Animal	Unknown;
	Unknown.makeSound();
	std::cout << std::endl;

	Cat	Pistache;
	Pistache.makeSound();
	std::cout << std::endl;

	Dog	Bolinhas;
	Bolinhas.makeSound();
	std::cout << std::endl;
}

int main()
{
	test1();
	test2();
	return (0);
}
