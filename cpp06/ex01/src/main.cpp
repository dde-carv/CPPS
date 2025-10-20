/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:47:10 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/20 11:46:44 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data	stats;
	stats.name = "Alberto";
	stats.age = 70;
	stats.grade = 95;

	std::cout << "Address: " << &stats << std::endl;
	std::cout << "Name: " << stats.name << std::endl;
	std::cout << "Age: " << stats.age << std::endl;
	std::cout << "Grade: " << stats.grade << "\n" << std::endl;

	Data	*result;

	result = Serializer::deserialize(Serializer::serialize(&stats));

	std::cout << "Address: " << result << std::endl;
	std::cout << "Name: " << result->name << std::endl;
	std::cout << "Age: " << result->age << std::endl;
	std::cout << "Grade: " << result->grade << std::endl;
	return 0;
}
