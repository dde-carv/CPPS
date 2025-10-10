/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:03:00 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 16:42:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	FragTrap	Joaozinho("Joaozinho");
	std::cout << "----- " << Joaozinho.getName() << " -----\n\n";
	std::cout << "	Attack: ";
	Joaozinho.attack("Monitor");
	std::cout << "\n	Take damage: ";
	Joaozinho.takeDamage(2);
	std::cout << "\n	Be repaired: ";
	Joaozinho.beRepaired(1);
	std::cout << "\n	3 HighFives request:\n\t";
	Joaozinho.highFivesGuys();
	std::cout << "\t";
	Joaozinho.highFivesGuys();
	std::cout << "\t";
	Joaozinho.highFivesGuys();
	std::cout << "\n	Hit Points: " << Joaozinho.getHitPoints();
	std::cout << "\n	Energy Points: " << Joaozinho.getEnergyPoints() << RST << std::endl;
}
