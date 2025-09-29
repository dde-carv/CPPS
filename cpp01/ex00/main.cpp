/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:57:09 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:57:10 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "Creating a Zombie in the stack." << std::endl;
	Zombie half_dead("Gostavo");
	half_dead.announce();

	std::cout << std::endl << "Creating a Zombie in the heap." << std::endl;
	Zombie *other_half = newZombie("Rita");
	other_half->announce();

	std::cout << std::endl << "Creating a Zombie outside the scope." << std::endl;
	randomChump("Ronaldo");
	std::cout << std::endl;

	delete other_half;
	return 0;
}
