/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:47:07 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/17 11:50:14 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RST "\033[0m"

#include <iostream>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);

	public:
		Serializer	&operator=(const Serializer &other);
		~Serializer();

		//uintptr_t	serialize(Data *ptr);
};
