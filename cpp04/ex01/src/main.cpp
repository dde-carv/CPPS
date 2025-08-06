/* #include "Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

void	test1()
{
	std::cout << "\n==========| TEST 1 |==========\n\n";

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
}

void	test2()
{
	std::cout << "\n==========| TEST 2 |==========\n\n";

	std::cout << "Construction:\n";
	Animal	*veterinary[]=
	{
		new Cat(),
		new Cat(),
		new Cat(),
		new Dog(),
		new Dog(),
		new Dog()
	};

	std::cout << "\nDestruction:\n";
	for (int i = 0; i < 6; i++)
		delete veterinary[i];
}

void	test3()
{
	std::cout << "\n==========| TEST 3 |==========\n\n";

	Cat	*Patareco = new Cat();

	std::cout << "\nPatareco:\n";
	Patareco->printCatIdeas(4);

	std::cout << std::endl;
	Patareco->setCatIdea(1, "Scratch my back!");
	Patareco->setCatIdea(2, "Scratch my back!");
	Patareco->setCatIdea(3, "Scratch my back!");
	Cat	*copy_cat = new Cat(*Patareco);
	Patareco->setCatIdea(1, "What a confortable box to sleep in...");
	copy_cat->setCatIdea(0, "Fur ball!");

	std::cout << "\nPatareco: (" << Patareco->getCatBrain() << ")\n";
	Patareco->printCatIdeas(4);
	std::cout << "\ncopy_cat: (" << copy_cat->getCatBrain() << ")\n";
	copy_cat->printCatIdeas(4);

	std::cout << std::endl;

	delete Patareco;
	delete copy_cat;
}

int main()
{
	test1();
	test2();
	test3();
	return 0;
} */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testSubject()
{
	std::cout << GREEN << "-= Subject Tests =-" << RST << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << YELLOW << "\nClean up" << RST << std::endl;
	delete j; // should not create a leak
	delete i;
}

void testDeepCopy_CopyConstructor()
{
	std::cout << GREEN << "\n-= Deep Copy with Copy Constructor =-" << RST << std::endl;

	Dog *originalDog = new Dog();
	originalDog->getDogBrain()->setIdea("Bones!! Must gnaw", "Original Dog");

	std::cout << YELLOW << "\ncopyDog using copy constructor" << RST << std::endl;
	Dog *copyDog = new Dog(*originalDog);

	std::cout << YELLOW << "\nPrint Ideas for both dogs" << RST << std::endl;
	originalDog->getDogBrain()->printIdeas("Original Dog", 0);
	copyDog->getDogBrain()->printIdeas("Copy Dog", 0);

	std::cout << YELLOW << "\nGive originalDog a new idea" <<
		RST << std::endl;
	originalDog->getDogBrain()->setIdea("Homan!! ahh...", "Original Dog");

	std::cout << YELLOW << "\nTesting for different ideas (deep copy)" <<
		RST << std::endl;
	originalDog->getDogBrain()->printIdeas("Original Dog", 0);
	copyDog->getDogBrain()->printIdeas("Copy Dog", 0);

	std::cout << YELLOW << "\nClean up" << RST << std::endl;
	delete originalDog;
	delete copyDog;
}

void testDeepCopy_CopyAssigment()
{
	std::cout << GREEN << "\n-= Deep Copy with assignment operator - and cats :( =-" << RST << std::endl;
	Cat * originalCat = new Cat();
	originalCat->getCatBrain()->setIdea("Fish!! Must eat", "Original Cat");
	Cat *assignedCat = new Cat();
	assignedCat->getCatBrain()->setIdea("Homan!! Dispise", "Assigned Cat");
	std::cout << YELLOW << "\nPrint Ideas for both cats before assignment" << RST << std::endl;
	originalCat->getCatBrain()->printIdeas("Original Cat", 0);
	assignedCat->getCatBrain()->printIdeas("Assigned Cat", 0);

	std::cout << YELLOW << "\nAssigniment: *assignedCat = *originalCat" << RST << std::endl;
	*assignedCat = *originalCat;

	std::cout << YELLOW <<
		"\nPrint Ideas for both cats after assignment (same ideas)" <<
		RST << std::endl;
	originalCat->getCatBrain()->printIdeas("Original Cat", 0);
	assignedCat->getCatBrain()->printIdeas("Assigned Cat", 0);

	std::cout << YELLOW << "\nGive originalCat a new idea..." << RST << std::endl;
	originalCat->getCatBrain()->setIdea("Give milk Homan!", "Original Cat");

	std::cout << YELLOW << "\nTesting for different ideas (deep copy)" <<
		RST << std::endl;
	originalCat->getCatBrain()->printIdeas("Original Cat", 0);
	assignedCat->getCatBrain()->printIdeas("Assigned Cat", 0);

	std::cout << YELLOW << "\nClean up" << RST << std::endl;
	delete originalCat;
	delete assignedCat;
}

void testDeepCopy_Stack()
{
	// Test deep copy with stack objects
	std::cout << GREEN << "\n-= Deep Copy on the stack =-" << RST << std::endl;
	{
		std::cout << YELLOW << "New stack Dog with idea" << RST << std::endl;
		Dog stackDog;
		stackDog.getDogBrain()->setIdea("I'm a stack dog!", "Stack Dog");

		std::cout << YELLOW << "\nCopy of stack Dog: Dog copyStackDog = stackDog" << RST << std::endl;
		Dog copyStackDog = stackDog;

		std::cout << YELLOW << "\nPrint Ideas for both dogs" << RST << std::endl;
		stackDog.getDogBrain()->printIdeas("Stack Dog", 0);
		copyStackDog.getDogBrain()->printIdeas("Copy Stack Dog", 0);

		std::cout << YELLOW << "\nGive stackDog a new idea" << RST << std::endl;
		stackDog.getDogBrain()->setIdea("My idea changed!", "Stack Dog");

		std::cout << YELLOW << "\nTest for different ideas (deep copy)" << RST << std::endl;
		stackDog.getDogBrain()->printIdeas("Stack Dog", 0);
		copyStackDog.getDogBrain()->printIdeas("Copy Stack Dog", 0);

		std::cout << YELLOW << "\nStack objects call destructor automagically" << RST << std::endl;
	}
}

int main()
{
	// Almost equal to test on subject, just looks nicer
	testSubject();
	// Implement and turn in more tests than the ones given above
	testDeepCopy_CopyConstructor();
	testDeepCopy_CopyAssigment();
	testDeepCopy_Stack();

	std::string ideias[4] = {"Bones!! Must gnaw", "Homan!! ahh...", "Fish!! Must eat", "Homan!! Dispise"};
	const int arraySize = 4;
	Animal *animalArray[arraySize];

	std::cout
		<< GREEN << "\n-= Subject array tests =-" << RST << std::endl;

	std::cout << YELLOW << "Creating an multipack of animals..." << RST << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		if (i < 2)
		{
			Dog *dog = new Dog();
			animalArray[i] = dog;
			std::cout << "Created Dog at position " << i << std::endl;
			dog->getDogBrain()->setIdea(ideias[i], dog->getType());
		}
		else
		{
			Cat *cat = new Cat();
			animalArray[i] = cat;
			std::cout << "Created Cat at position " << i << std::endl;
			cat->getCatBrain()->setIdea(ideias[i], cat->getType());
		}
	}

	// add new ideia to dog 1
	std::cout << YELLOW << "\n Dog 1 gets a new ideia" << RST << std::endl;
	static_cast<Dog *>(animalArray[1])->getDogBrain()->setIdea("Hmm, what is 42?", animalArray[1]->getType());

	std::cout << YELLOW << "\nThinking" << RST << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		if (animalArray[i]->getType() == "Dog")
		{
			static_cast<Dog *>(animalArray[i])->getDogBrain()->printIdeas(animalArray[i]->getType(), i);
		}
		if (animalArray[i]->getType() == "Cat")
		{
			static_cast<Cat *>(animalArray[i])->getCatBrain()->printIdeas(animalArray[i]->getType(), i);
		}
	}

	std::cout << YELLOW << "\nClean up array" << RST << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		delete animalArray[i];
	}

	std::cout << GREEN << "\nAll tests completed" << RST << std::endl;

	return 0;
}
