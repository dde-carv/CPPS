/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:23:25 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/24 11:49:30 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {
	PhoneBook book;
	std::string option;

	while (1) {
		std::cout << "Welcome to my crappy awesome phonebook!" << std::endl \
		<< "Choose one Command: " << std::endl \
		<< "ADD(save a new contact)" << std::endl \
		<< "SEARCH(display a specific contact)" << std::endl \
		<< "EXIT(exit the program)" << std::endl;

		std::getline(std::cin, option);
		if (!std::cin)
			break ;

		if (option == "ADD")
			book.add_contact();
		else if (option == "SEARCH")
			book.display_contacts();
		else if (option == "EXIT")
			break ;
		else
			std::cerr << "Invalid input, try again!!" << std::endl;
	}
	std::cout << "Thank you for using my crappy awesome phonebook!" << std::endl;
}
