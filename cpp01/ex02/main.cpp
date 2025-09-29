/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:58:10 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:58:11 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory address of the string variable: " << &string << std::endl;
	std::cout << "Memory address of the string pointer: " << stringPTR << std::endl;
	std::cout << "Memory address of the string reference: " << &stringREF << std::endl;

	std::cout << std::endl << "Value of the string variable: " << string << std::endl;
	std::cout << "Value of the string pointer: " << *stringPTR << std::endl;
	std::cout << "Value of the string reference: " << stringREF << std::endl;
	return 0;
}
