/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:47:13 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/20 11:52:24 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

/************ Constructors and Destructor ************/

Serializer::Serializer()
{
	std::cout << GREEN << "Serializer default constructor called." << RST << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << GREEN << "Serializer copy constructor called." << RST << std::endl;

	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;

	std::cout << YELLOW << "Serializer copy assignment operator called." << RST << std::endl;

	return *this;
}

Serializer::~Serializer()
{
	std::cout << RED << "Serializer destructor called." << RST << std::endl;
}

/************ Member Functions ************/

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
