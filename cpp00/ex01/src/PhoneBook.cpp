/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:23:27 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/25 14:46:37 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add_contact() {
	std::string	prompt;

	system("sleep 1");
	system("clear");
	std::cout << "\033[35m" << "/* *************************************** *\\" << "\033[0m" << std::endl;
	std::cout << "\033[32m" << "Fill the form bellow to add a contact:" << "\033[0m" << std::endl;
	for (int i = 6; i >= 0; i--)
		contact[i + 1] = contact[i];
	contact[0].fill_form();
	if (std::cin) {
		std::cout << "\033[33m" << "         Contact added successfully!!        " << "\033[0m" << std::endl;
		std::cout << "\033[35m" << "\\* *************************************** */" << "\033[0m" << std::endl;
		std::cout << std::endl << "\033[31m" << "Press enter to continue!" << "\033[0m" << std::endl;
		std::getline(std::cin, prompt);
		if (!std::cin)
			return ;
	}
	system("clear");
}

void	PhoneBook::display_contacts() {
	int			i;
	std::string	prompt;

	system("sleep 1");
	system("clear");
	if (contact[0].is_empty()) {
		std::cerr << "\033[31m" << "There is no contact in your crappy awesome phonebook!" << "\033[0m" << std::endl;
		system("sleep 2");
		system("clear");
		return ;
	}
	std::cout << "\033[35m" << "/* *************************************** *\\" << "\033[0m" << std::endl;
	std::cout << "\033[35m" << "|     Index|First Name| Last Name|  Nickname|" << "\033[0m" << std::endl;
	for (i = 0; i <= 7 && !contact[i].is_empty(); i++) {
		std::cout << "\033[35m" << "|" << "         " << i + 1 << "|" << "\033[0m";
		contact[i].display_line();
	}
	std::cout << std::endl << "\033[32m" << "Choose the index of the contact to be displayed: " << "\033[0m";
	while (std::cin) {
		std::getline(std::cin, prompt);
		if (!std::cin)
			break ;
		if (prompt.length() == 1)
			i = prompt[0] - 48;
		else
			i = 0;
		if (i >= 1 && i <= 8 && !contact[i - 1].is_empty()) {
			std::cout << std::endl;
			contact[i - 1].display_info();
			break ;
		}
		else
			std::cerr << "\033[31m" << "Invalid index, try again: " << "\033[0m";
	}
	if (std::cin) {
		std::cout << "\033[35m" << "\\* *************************************** */" << "\033[0m" << std::endl;
		std::cout << std::endl << "\033[31m" << "Press enter to continue!" << "\033[0m" << std::endl;
		std::getline(std::cin, prompt);
		if (!std::cin)
			return ;
	}
	system("clear");
}
