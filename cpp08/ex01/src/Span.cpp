/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:22:09 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/28 14:18:43 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span()
{
	_vec.reserve(0);
}

Span::Span(unsigned int N)
{
	_vec.reserve(N);
}

Span::Span(const Span &other)
{
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		std::vector<int>	newVec;
		newVec.reserve(other._vec.capacity());
		newVec = other._vec;
		std::swap(this->_vec, newVec);
	}
	return *this;
}

Span::~Span()
{}

std::vector<int>	Span::getVec()const
{
	return _vec;
}

void	Span::addNumber(int nbr)
{
	if (_vec.size() == _vec.capacity())
		throw MaxCapacity();
	_vec.push_back(nbr);
}

void	Span::addRandom(int min, int max, unsigned int members)
{
	if (min > max)
		throw MaxLessThanMin();
	if (_vec.size() == _vec.capacity())
		throw MaxCapacity();
	if ((members + _vec.size()) > _vec.capacity())
		throw MoreMembersThanCapacity();
	srand(time(NULL));
	for (unsigned int i = 0; (i < members) && (_vec.size() != _vec.capacity()); i++)
		_vec.push_back(min + std::rand() % (max - min + 1));
}

int		Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw LessThanTwo();
	std::vector<int>	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int	span = *(tmp.end() - 1) - *tmp.begin();
	for (std::vector<int>::iterator it = tmp.begin(); it + 1 != tmp.end(); ++it)
	{
		if (*(it + 1) - *it < span)
			span = *(it + 1) - *it;
	}
	return span;
}

int		Span::longestSpan()
{
	if (_vec.size() < 2)
		throw LessThanTwo();
	return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
}

void	Span::printVec()
{
	std::cout << "|";
	for (std::vector<int>::iterator i = _vec.begin(); i != _vec.end(); ++i)
		std::cout << " " << *i << " |";
	std::cout << std::endl;
}

const char* Span::MaxCapacity::what() const throw()
{
	return "Can't add more numbers, capacity is full!!";
}

const char* Span::LessThanTwo::what() const throw()
{
	return "Can't find the span, needs at least two numbers!!";
}

const char* Span::MoreMembersThanCapacity::what() const throw()
{
	return "Can't add randomly, there is more numbers to add than capacity!!";
}

const char* Span::MaxLessThanMin::what() const throw()
{
	return "Can't add randomly, the max value can't be less then min value!!";
}
