/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:34:25 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/21 10:49:37 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

Base	*generate()
{
	Base	*base;

	switch (rand() % 3)
	{
		case 0:
			std::cout << "Generating object of type A." << std::endl;
			base = new A();
			break;

		case 1:
			std::cout << "Generating object of type B." << std::endl;
			base = new B();
			break;

		case 2:
			std::cout << "Generating object of type C." << std::endl;
			base = new C();
			break;
	}
	return base;
}

void	identify(Base *p)
{
	Base	*identifier;

	identifier = dynamic_cast<A *>(p);
	if (identifier)
	{
		std::cout << "This object is type A." << std::endl;
		return ;
	}

	identifier = dynamic_cast<B *>(p);
	if (identifier)
	{
		std::cout << "This object is type B." << std::endl;
		return ;
	}

	identifier = dynamic_cast<C *>(p);
	if (identifier)
	{
		std::cout << "This object is type C." << std::endl;
		return ;
	}
	std::cout << "Couldn't identify the object type." << std::endl;
}

void	identify(Base &p)
{
	A	a;
	B	b;
	C	c;

	try
	{
		a = dynamic_cast<A &>(p);
		std::cout << "This object is type A." << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}

	try
	{
		b = dynamic_cast<B &>(p);
		std::cout << "This object is type B." << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}

	try
	{
		c = dynamic_cast<C &>(p);
		std::cout << "This object is type C." << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
}
