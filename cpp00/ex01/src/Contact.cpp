/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:23:30 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/24 17:33:59 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::validate_number() {
	if (!std::cin)
		return ;

}

int	Contact::is_empty() {

}

std::string	Contact::get_input(std::string message) {

}

void	Contact::fill_form() {
	first_name = get_input("First Name: ");
	last_name = get_input("Last Name: ");
	nickname = get_input("Nickname: ");
	while (std::cin && phone_number.empty()) {
		phone_number = get_input("Phone Number: ");
		validate_number();
	}
	darkest_secret = get_input("Darkest Secret: ");
}
