/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:23:25 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/25 17:02:44 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {
	PhoneBook book;
	std::string option;

	system("clear");
	std::cout << "\033[35m" << "Welcome to my crappy awesome phonebook!" << "\033[0m" << std::endl << std::endl;
	while (std::cin) {
		std::cout << "\033[36m" << "Choose one Command: " << std::endl \
		<< "ADD(save a new contact)" << std::endl \
		<< "SEARCH(display a specific contact)" << std::endl \
		<< "EXIT(exit the program)" << std::endl \
		<< "Option: " << "\033[0m";

		std::getline(std::cin, option);
		if (!std::cin)
			break ;

		if (option == "ADD")
			book.add_contact();
		else if (option == "SEARCH")
			book.display_contacts();
		else if (option == "EXIT")
			break ;
		else {
			std::cerr << "\033[31m" << "Invalid input, try again!!" << "\033[0m" << std::endl;
			system("sleep 1");
			system("clear");
		}
	}
	system("sleep 1");
	system("clear");
	std::cout << "\033[35m" << std::endl << "Thank you for using my crappy awesome phonebook!" << "\033[0m" << std::endl << std::endl;
	system("sleep 2");
	system("timeout 5 curl parrot.live");
	return 0;
}
