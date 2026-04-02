/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:43:51 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/02 16:44:55 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error\n";
		return 1;
	}

	std::vector<int>	vec;
	std::deque<int>		deq;

	for (int i = 1; i < ac; i++)
	{
		std::string	s(av[i]);

		if (s.empty())
		{
			std::cerr << "Error\n";
			return 1;
		}
		for (std::size_t j = 0; j < s.size(); j++)
		{
			if (!std::isdigit(static_cast<unsigned char>(s[j])))
			{
				std::cerr << "Error\n";
				return 1;
			}
		}

		long	num = std::atol(av[i]);
		if (num <= 0 || num > INT_MAX)
		{
			std::cerr << "Error\n";
			return 1;
		}
		vec.push_back(static_cast<int>(num));
		deq.push_back(static_cast<int>(num));
	}

	std::cout << "Before:";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl;

	PmergeMe	sorter;
	double		timeToVec = sorter.sortVector(vec);
	double		timeToDeq = sorter.sortDeque(deq);

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << vec.size()
			<< " elements with std::vector : " << timeToVec << " us\n"
			<< "Time to process a range of " << deq.size()
			<< " elements with std::deque  : " << timeToDeq << " us\n";

	return 0;
}
