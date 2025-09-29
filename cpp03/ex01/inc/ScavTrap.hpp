/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:02:22 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 17:02:23 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_guardGate;

	public:
/************ Constructors and Destructor ************/

		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &object);
		~ScavTrap();

/************ Operator ************/

		ScavTrap		&operator=(const ScavTrap &copy);

/************ Getter ************/

		bool			getGardGate();

/************ Setter ************/

		void			setGardGate(bool mode);

/************ Member Functions ************/

		void			attack(const std::string& target);
		void			guardGate();
};
