/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:02:46 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 17:02:47 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
/************ Constructors and Destructor ************/

		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &object);
		~FragTrap();

/************ Operator ************/

		FragTrap		&operator=(const FragTrap &copy);

/************ Member Function ************/

		void			highFivesGuys(void);
};
