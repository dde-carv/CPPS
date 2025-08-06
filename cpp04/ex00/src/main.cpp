/* #include "Animal.hpp"
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

	Cat CopyCat(Pistache);
	CopyCat.makeSound();
	std::cout << std::endl;

	Dog CopyDog(Bolinhas);
	CopyDog.makeSound();
	std::cout << std::endl;
}

int main()
{
	test1();
	test2();
	return (0);
} */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testSubject()
{
	std::cout << GREEN << "-= Subject Tests =-" << RST << std::endl;

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "j is a: " << j->getType() << std::endl;
	std::cout << "i is a: " << i->getType() << std::endl;

	std::cout << YELLOW << "\nMaking sounds:" << RST << std::endl;
	std::cout << "Dog says: ";
	j->makeSound();
	std::cout << "Cat says: ";
	i->makeSound();
	std::cout << "Generic animal says: ";
	meta->makeSound();
	std::cout << std::endl;

	std::cout << YELLOW << "\nClean up" << RST << std::endl;
	delete meta;
	delete j;
	delete i;
}

void testStackInstances()
{
	std::cout << "\n"
			  << GREEN << "-= Stack Test =-" << RST << std::endl;

	std::cout << YELLOW << "Creating Stack Animals:" << RST << std::endl;
	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << YELLOW << "\nTypes" << RST << std::endl;
	std::cout << "Animal type: " << animal.getType() << std::endl;
	std::cout << "Dog type: " << dog.getType() << std::endl;
	std::cout << "Cat type: " << cat.getType() << std::endl;

	std::cout << YELLOW << "\nMaking sounds:" << RST << std::endl;
	std::cout << "Animal sound: " << std::endl;
	animal.makeSound();
	std::cout << "Dog sound: ";
	dog.makeSound();
	std::cout << "Cat sound: ";
	cat.makeSound();
	std::cout << YELLOW << "\nClean up" << RST << std::endl;
}

void testCopyConstructorAndAssignment()
{
	std::cout << GREEN << "\n-= Test Copy Constructor and Assignment =-"
			  << RST << std::endl;

	std::cout << YELLOW << "Creating original dog:" << RST << std::endl;
	Dog originalDog;
	std::cout << YELLOW << "\nCopy of dog with copy constructor" << RST << std::endl;
	Dog copiedDog(originalDog);
	std::cout << YELLOW << "\nAnother dog to use with assignment" << RST << std::endl;
	Dog assignedDog;
	std::cout << YELLOW << "\nAssigniment of originalDog to assignedDog" << RST << std::endl;
	assignedDog = originalDog;

	std::cout << YELLOW << "\nall dogs make the same sound" << RST << std::endl;
	std::cout << "Original dog: ";
	originalDog.makeSound();
	std::cout << "Copied dog: ";
	copiedDog.makeSound();
	std::cout << "Assigned dog: ";
	assignedDog.makeSound();

	std::cout << YELLOW << "\nIt' the same with cats, but i don't like them" << RST << std::endl;
	std::cout << YELLOW << "\nClean up" << RST << std::endl;
}

void testAnimalArrays()
{
	std::cout << GREEN << "\n-= 'member Zombie Hordes? =-" << RST << std::endl;

	const int arraySize = 4;
	Animal *animalArray[arraySize];

	std::cout << YELLOW << "Create a pack of animals" << RST << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		if (i < 2)
		{
			animalArray[i] = new Dog();
			std::cout << "Created Dog at position " << i << std::endl;
		}
		else
		{
			animalArray[i] = new Cat();
			std::cout << "Created Cat at position " << i << std::endl;
		}
	}

	std::cout << YELLOW << "\nMaking sounds" << RST << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Animal " << i << " (type: " << animalArray[i]->getType()
		 << ") says: ";
		animalArray[i]->makeSound();
	}

	std::cout << YELLOW << "\nClean up array" << RST << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		delete animalArray[i];
	}
}

void testCustomTypeConstructor()
{
	std::cout << GREEN << "\n-= Test Constructor with type name=-" << RST
			  << std::endl;

	std::cout << YELLOW << "Create custom type animals" << RST << std::endl;

	Dog greatDane("Great Dane");
	Cat sphinx("Sphinx Cat");
	Animal unknown("Unknown Animal");

	std::cout << YELLOW << "\nTypes" << RST << std::endl;
	std::cout << "Dog type: " << greatDane.getType() << std::endl;
	std::cout << "Cat type: " << sphinx.getType() << std::endl;
	std::cout << "Unknown type: " << unknown.getType() << std::endl;

	std::cout << YELLOW << "\nMaking sounds" << RST << std::endl;
	std::cout << "Great Dane: ";
	greatDane.makeSound();
	std::cout << "Sphinx Cat: ";
	sphinx.makeSound();
	std::cout << "Unknown Animal: ";
	unknown.makeSound();
	std::cout << YELLOW << "\n\nClean up" << RST << std::endl;
}

void testWrongAnimal()
{
	std::cout << GREEN << "\n-= Testing WrongAnimal Polymorphism =-" << RST << std::endl;

	std::cout << YELLOW << "Create WrongAnimals" << RST << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	// WrongCat in the Heap for comparison
	WrongCat heapWrongCat;

	std::cout << YELLOW << "\nTypes" << RST << std::endl;
	std::cout << "WrongAnimal type: " << wrongMeta->getType() << std::endl;
	std::cout << "WrongCat (inheritance from WrongAnimal) type: " << wrongCat->getType() << std::endl;
	std::cout << "Heap WrongCat type: " << heapWrongCat.getType() << std::endl;

	std::cout << YELLOW << "\nMaking sounds" << RST << std::endl;

	// This will call WrongAnimal::makeSound
	std::cout << "WrongAnimal sound: ";
	wrongMeta->makeSound();

	// This calls WrongAnimal::makeSound, NOT WrongCat::makeSound
	// shows virtual is needed for proper polymorphism
	std::cout << "WrongCat (inheritance from WrongAnimal) sound: ";
	wrongCat->makeSound();

	// This works, but is not polymorphism: calls WrongCat::makeSound
	std::cout << "Heap WrongCat sound: ";
	heapWrongCat.makeSound();

	std::cout << YELLOW << "\nClean up" << RST << std::endl;
	delete wrongMeta;
	delete wrongCat;
}
int main()
{
	// Almost equal to test on subject, just looks nicer
	testSubject();
	// Implement and turn in more tests than the ones given above
	testStackInstances();
	testCopyConstructorAndAssignment();
	testAnimalArrays();
	testCustomTypeConstructor();
	testWrongAnimal();

	std::cout << "\n"
			  << GREEN << "All tests completed!" << RST << std::endl;

	return 0;
}

