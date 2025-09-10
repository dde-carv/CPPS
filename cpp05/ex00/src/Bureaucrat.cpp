#include "Bureaucrat.hpp"

/************ Constructors and Destructor ************/

Bureaucrat::Bureaucrat() : _name("Alberto"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called\n" << RST;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		checkGrade();
		std::cout << GREEN << "Bureaucrat costum constructor called\n" << RST;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	*this = other;

	std::cout << GREEN << "Bureaucrat copy constructor called\n" << RST;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREEN << "Bureaucrat default destructor called\n" << RST;
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

void	Bureaucrat::checkGrade()
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

/************ Execeptions ************/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The Bureaucrat grade is too high!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The Bureaucrat grade is too low!!";
}

/************ Operators ************/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;

	std::cout << GREEN << "Bureaucrat copy assignment operator called\n" << RST;

	return *this;
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << " , bureaucrat grade " << object.getGrade() << ".\n";
	return stream;
}
