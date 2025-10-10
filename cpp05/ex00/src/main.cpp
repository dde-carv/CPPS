/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:07:06 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/10 15:46:38 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

void	test1()
{
	std::cout << "\n==========| TEST 1 |==========\n\n";
	Bureaucrat guy("Guy", 4);
	Bureaucrat dennis("Dennis", -5);
	Bureaucrat tony("Tony", 149);
	Bureaucrat vanDamme("Van Damme", 174);

	std::cout << "\n";

	guy.incrementGrade();
	guy.incrementGrade();
	guy.incrementGrade();
	guy.incrementGrade();
	tony.decrementGrade();
	tony.decrementGrade();

	std::cout << "\n";
}

void	test2()
{
	std::cout << "\n==========| TEST 2 |==========\n\n";
	Bureaucrat phill("Phill", 42);
	Bureaucrat bob (phill);

	std::cout << "\n";

	Bureaucrat libna = bob;

	std::cout << "\n";
	std::cout << "This is " << phill;
	std::cout << "This is " << bob;
	std::cout << "This is " << libna;
	std::cout << "\n";
}

int	main()
{
	test1();
	test2();
}
