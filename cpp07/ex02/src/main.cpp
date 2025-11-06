/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:02:10 by dde-carv          #+#    #+#             */
/*   Updated: 2025/11/06 11:06:25 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main()
{
	Array<int>			integer;
	Array<float>		floating(3);
	Array<float>		copy(floating);
	Array<char>			character(6);

	std::cout << "----- SIZES -----" << std::endl;
	std::cout << "integer = " << integer.size() << std::endl;
	std::cout << "floating = " << floating.size() << std::endl;
	std::cout << "copy = " << copy.size() << std::endl;
	std::cout << "character = " << character.size() << std::endl;

	try
	{
		std::cout << std::endl << "----- OUT OF BOUNDS TEST -----" << std::endl;
		std::cout << "floating[2] = " << floating[2] << std::endl;
		std::cout << "floating[16] = " << floating[16] << std::endl;
		std::cout << "I shouldn't print this!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "----- OUT OF BOUNDS TEST -----" << std::endl;
		std::cout << "character[2] = " << character[2] << std::endl;
		std::cout << "character[16] = " << character[16] << std::endl;
		std::cout << "I shouldn't print this!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
