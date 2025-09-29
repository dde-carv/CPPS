#include "Bureaucrat.hpp"

/************ Constructors and Destructor ************/

Bureaucrat::Bureaucrat() : _name("Leclerc"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << std::endl << RST;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << GREEN << "Bureaucrat custom constructor called" << std::endl << RST;
	try
	{
		if (_grade < 1)
			throw GradeTooHighException();
		if (_grade > 150)
			throw GradeTooLowException();
		std::cout << GREEN << "Bureaucrat " << _name << " has a valid Grade" << " >> "\
		 << _grade << ", accepted!" << std::endl << RST;
	}
	catch(const std::exception &e)
	{
		std::cout << RED << "Constructor exception (" << _name << "): "\
		 << e.what() << std::endl << RST;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	std::cout << GREEN << "Bureaucrat copy constructor called\n" << RST;

	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREEN << "Bureaucrat default destructor called" << std::endl << RST;
}

/************ Getters ************/

const std::string	Bureaucrat::getName() const
{
	return _name;
}

int					Bureaucrat::getGrade() const
{
	return _grade;
}

/************ Member Functions ************/

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade == 1)
			throw GradeTooHighException();
		_grade--;
		std::cout << PURPLE << "Grade Incremented -> " << *this << RST;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Grade incrementing exception (" << _name << "): "\
		 << e.what() << std::endl << RST;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade == 150)
			throw GradeTooLowException();
		_grade++;
		std::cout << YELLOW << "Grade Decremented -> " << *this << RST;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Grade decrementing exception (" << _name << "): "\
		 << e.what() << std::endl << RST;
	}
}

/************ Execeptions ************/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "the Bureaucrat grade is too high!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "the Bureaucrat grade is too low!!";
}

/************ Operators ************/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;

	std::cout << GREEN << "Bureaucrat copy assignment operator called" << std::endl << RST;

	return *this;
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << " , bureaucrat grade " << object.getGrade() << "." << std::endl;
	return stream;
}
