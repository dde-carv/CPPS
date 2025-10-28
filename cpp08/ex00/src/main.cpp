/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:44:19 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/28 15:59:12 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int	main()
{
	{
	std::cout << "----- DEQUE -----" << std::endl;
	std::deque<int> d;
	for (int i=1; i<=5; i++)
		d.push_back(i);
	try
	{
		std::cout << "find(1): " << *easyfind(d, 1) << std::endl;
		std::cout << "find(404): " << *easyfind(d, 404) << std::endl;
		std::cout << "Shouldn't print this!\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	}

	{
	std::cout << "----- VECTOR -----" << std::endl;
	std::vector<int> v;
	for (int i=0; i<=5; i++)
		v.push_back(i);
	try
	{
		std::cout << "find(5): " << *easyfind(v, 5) << std::endl;
		std::cout << "find(404): " << *easyfind(v, 404) << std::endl;
		std::cout << "Shouldn't print this!\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	}

	{
	std::cout << "----- LIST -----" << std::endl;
	int myints[] = {75,23,65,42,13};
	std::list<int> l (myints,myints+5);
	try
	{
		std::cout << "find(42): " << *easyfind(l, 42) << std::endl;
		std::cout << "find(404): " << *easyfind(l, 404) << std::endl;
		std::cout << "Shouldn't print this!\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	}
	return 0;
}
