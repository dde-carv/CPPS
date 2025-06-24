/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:23:27 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/24 14:14:12 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add_contact() {
	std::cout << "/* ************************************************************************** *\\" << std::endl;
	std::cout << "Fill the form bellow to add a contact:" << std::endl;

	for (int i = 6; i >= 0; i--)
		contact[i + 1] = contact[i];

	contact[0].fill_form();

}
