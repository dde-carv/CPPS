/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:31:28 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/21 10:45:53 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

int	main()
{
	Base	*test1;
	Base	*test2;
	Base	*test3;

	srand(time(NULL));

	test1 = generate();
	test2 = generate();
	test3 = generate();

	std::cout << "\nBase* identify tests\n" << std::endl;
	std::cout << "Test 1: ";
	identify(test1);
	std::cout << "Test 2: ";
	identify(test2);
	std::cout << "Test 3: ";
	identify(test3);

	std::cout << "\nBase& identify tests\n" << std::endl;
	std::cout << "Test 1: ";
	identify(*test1);
	std::cout << "Test 2: ";
	identify(*test2);
	std::cout << "Test 3: ";
	identify(*test3);

	delete test1;
	delete test2;
	delete test3;
	return 0;
}
