/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:59:33 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:59:34 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl
{
private:
	void		_debug();
	void		_info();
	void		_warning();
	void		_error();
	void		(Harl::*_level[4])();
	std::string	_level_finder[4];
public:
	Harl();
	~Harl();
	void	complain(std::string level);
};
