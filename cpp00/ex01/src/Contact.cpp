/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:23:30 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/25 16:39:04 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::display_info() {
	std::cout << "\033[32m" << "First Name:        " << "\033[0m" << first_name << std::endl \
	<< "\033[32m" << "Last Name:         " << "\033[0m" << last_name << std::endl \
	<< "\033[32m" << "Nickname:          " << "\033[0m" << nickname << std::endl \
	<< "\033[32m" << "Phone Number:      " << "\033[0m" << phone_number << std::endl \
	<< "\033[32m" << "Darkest Secret 👀: " << "\033[0m" << darkest_secret << std::endl;
}

void	Contact::display_line() {
	std::string str[] = {first_name, last_name, nickname, ""};
	for (int i = 0; !str[i].empty(); i++) {
		if (str[i].length() > 10)
			std::cout << "\033[35m" << str[i].substr(0, 9) << ".|" << "\033[0m";
		else
			std::cout << "\033[35m" << std::setw(10) << str[i].substr(0, 10) << "|" << "\033[0m";
	}
	std::cout << std::endl;
}

void	Contact::validate_number() {
	if (!std::cin)
		return ;
	if (!isdigit(phone_number[0]) && phone_number[0] != '+')
		phone_number = "";
	for (int i = 1; phone_number[i]; i++) {
		if(!isdigit(phone_number[i]))
			phone_number = "";
	}
	if (phone_number.empty())
		std::cerr << "\033[31m" << "Invalid phone number, try again!" << "\033[0m" << std::endl;
}

int	Contact::is_empty() {
	if (first_name.empty())
		return 1;
	return 0;
}

std::string	Contact::format_field(std::string prompt, int is_alpha) {
	int i = -1;

	while (prompt[++i]) {
		if ((isspace(prompt[i]) || prompt[i] == 27 || prompt[i] == 127) && is_alpha != 4)
			return "";
		if (is_alpha == 1 && !std::isalpha(prompt[i]))
			return "";
		if (is_alpha == 2 && !std::isalnum(prompt[i]))
			return "";
		if (is_alpha == 3 && prompt[i] <= 32)
			return "";
	}
	return prompt;
}

std::string	Contact::get_input(std::string message, int is_alpha) {
	std::string	prompt;

	while (std::cin) {
		std::cout << "\033[32m" << message << "\033[0m";
		std::getline(std::cin, prompt);
		if (!std::cin)
			break ;
		prompt = format_field(prompt, is_alpha);
		if (!prompt.empty())
			break ;
		else
			std::cerr << "\033[31m" << "Invalid input, try againg!" << "\033[0m" << std::endl;
	}
	return prompt;
}

void	Contact::fill_form() {
	first_name = get_input("First Name: ", 1);
	last_name = get_input("Last Name: ", 1);
	nickname = get_input("Nickname: ", 3);
	phone_number = "";
	while (std::cin && phone_number.empty()) {
		phone_number = get_input("Phone Number: ", 0);
		validate_number();
	}
	darkest_secret = get_input("Darkest Secret: ", 4);
}
