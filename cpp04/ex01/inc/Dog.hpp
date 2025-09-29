/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:04:17 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 17:04:18 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &object);
		virtual ~Dog();

		Dog			&operator=(const Dog &copy);

		Brain		*getBrain()const;

		virtual void	makeSound()const;
};
