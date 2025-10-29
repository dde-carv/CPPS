/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:51:48 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/29 10:30:30 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

int	main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Last element of stack: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "How many elements in stack: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	++it;
	std::cout << "Iterator after 1 iteration: " << *it << std::endl;
	--it;

	++rit;
	std::cout << "Reverse iterator after 1 iteration: " << *rit << std::endl;
	--rit;

	std::cout << "How many elements in stack: " << mstack.size() << "\n" << std::endl;
	std::cout << "Iterating throught the stack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;

	std::cout << "Reverse iterating throught the stack:" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::stack<int> s(mstack);
	return 0;
}
