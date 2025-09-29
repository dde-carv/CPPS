/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:57:44 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:57:45 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int			nb_of_zombies = 5;
	std::string	name = "Judas";

	std::cout << "Creating a hord of " << nb_of_zombies << " zombies named " << name << "." << std::endl;
	Zombie *horde = zombieHorde(nb_of_zombies, name);

	std::cout << "\nAnnouncing all the zombies one by one." << std::endl;
	for (int i = 0; i < nb_of_zombies; i++)
	{
		std::cout << "Zombie number: " << i << std::endl;
		horde[i].announce();
	}

	std::cout << std::endl << "Deleting the horde." << std::endl;
	delete[] horde;
	return 0;
}
