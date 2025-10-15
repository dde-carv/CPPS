#include "../inc/ScalarConverter.hpp"

/************ Constructors and Destructor ************/

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "ScalarConverter default constructor called." << RST << std::endl;
}

ScalarConverter::ScalarConverter(/* Add parameters here */)
{
	std::cout << GREEN << "ScalarConverter custom constructor called." << RST << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << GREEN << "ScalarConverter copy constructor called." << RST << std::endl;

	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		// Copy attributes here
	}

	std::cout << YELLOW << "ScalarConverter copy assignment operator called." << RST << std::endl;

	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destructor called." << RST << std::endl;
}

/************ Member Functions ************/

	// Add member functions here

