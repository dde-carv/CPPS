/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:19:57 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/23 16:57:28 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac,char *av[]) {
	int i = 1;
	int j;

	while (ac > i){
		j = -1;
		while (av[i][++j])
			av[i][j] = std::toupper(av[i][j]);
		std::cout << av[i];
		i++;
	}
	if (i == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
