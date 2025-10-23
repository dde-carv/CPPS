/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:48:46 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/23 15:44:30 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

template<typename T>
void print(T const n)
{
	std::cout << n << " ";
}

template<typename T>
void increment(T &n)
{
	n++;
}

int main()
{
	char	arr1[] = "Bom dia alergia";
	double	arr2[] = {2.42, 4.42, 8.42, 16.42, 32.42, 64.42};
	int		arr3[] = {2, 4, 8, 16, 32, 64, 128, 256};

	std::cout << "----- VALUES BEFORE INCREMENTATION -----" << std::endl;
	iter(arr1, 16, print<char>);
	std::cout << std::endl;
	iter(arr2, 6, print<double>);
	std::cout << std::endl;
	iter(arr3, 8, print<int>);
	std::cout << std::endl;

	iter(arr1, 16, &increment<char>);
	iter(arr2, 6, &increment<double>);
	iter(arr3, 8, &increment<int>);

	std::cout << std::endl << "----- VALUES AFTER INCREMENTATION -----" << std::endl;
	iter(arr1, 16, print<char>);
	std::cout << std::endl;
	iter(arr2, 6, print<double>);
	std::cout << std::endl;
	iter(arr3, 8, print<int>);
	std::cout << std::endl;
}
