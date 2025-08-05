#include "AAnimal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

void testAbstractAnimalClass()
{
	std::cout << GREEN << "\n-= Testing Abstract Animal =-" << RST << std::endl;

	std::cout << YELLOW << "Check code to validate class is indeed abstract\n" << RST << std::endl;
	/* Uncomment to trigger compiler error */
	/* Error: Cannot instantiate abstract class */
	// AAnimal animal;

	/* Uncomment to trigger compiler error */
	/* Error: Cannot instantiate abstract class */
	// AAnimal* abstractAnimal = new AAnimal();

	std::cout << YELLOW << "Creating animals through concrete classes:" << RST << std::endl;

	// These should work fine
	AAnimal *dog = new Dog();
	AAnimal *cat = new Cat();

	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Dog sound: ";
	dog->makeSound();

	std::cout << "Cat type: " << cat->getType() << std::endl;
	std::cout << "Cat sound: ";
	cat->makeSound();

	std::cout << YELLOW << "\nPolymorphism" << RST << std::endl;
	AAnimal *animals[2] = {dog, cat};
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Animal " << i << " (type: " << animals[i]->getType() << ") says: ";
		animals[i]->makeSound();
	}

	std::cout << YELLOW << "\nClean up" << RST << std::endl;
	delete dog;
	delete cat;
}

int main()
{
	testAbstractAnimalClass();

	std::cout << GREEN << "\nAll tests completed" << RST << std::endl;

	return 0;
}
