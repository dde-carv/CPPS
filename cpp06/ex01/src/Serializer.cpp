/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:47:13 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/17 11:49:15 by dde-carv         ###   ########.fr       */
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

	// Add member functions here

