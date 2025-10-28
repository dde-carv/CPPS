/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:22:42 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/28 16:19:59 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main()
{
	srand(time(NULL));

	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//sp.addNumber(20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	Span ps = Span(1000);
	try
	{
		ps.addNumber(6);
		ps.addRandom(1, 100000, 999);
		//sp.addNumber(20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << ps.shortestSpan() << std::endl;
		std::cout << ps.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
