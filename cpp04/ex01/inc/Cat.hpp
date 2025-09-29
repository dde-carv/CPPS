/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:04:15 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 17:04:16 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &object);
		virtual ~Cat();

		Cat			&operator=(const Cat &copy);

		Brain		*getBrain()const;

		virtual void		makeSound()const;
};
