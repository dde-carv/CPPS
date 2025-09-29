/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:05:51 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 17:05:52 by dde-carv         ###   ########.fr       */
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

class AAnimal
{
	protected:
		std::string _type;
		AAnimal();
		AAnimal(const std::string type);

	public:
		AAnimal(const AAnimal &object);
		virtual ~AAnimal();

		void			setType(std::string type);
		std::string		getType()const;

		AAnimal			&operator=(const AAnimal &copy);

		virtual void	makeSound()const = 0;
};
