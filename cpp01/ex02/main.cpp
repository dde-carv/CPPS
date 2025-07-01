#include <iostream>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory address of the string variable: " << &string << std::endl;
	std::cout << "Memory address of the string pointer: " << stringPTR << std::endl;
	std::cout << "Memory address of the string reference: " << &stringREF << std::endl;

	std::cout << std::endl << "Value of the string variable: " << string << std::endl;
	std::cout << "Value of the string pointer: " << *stringPTR << std::endl;
	std::cout << "Value of the string reference: " << stringREF << std::endl;
	return 0;
}