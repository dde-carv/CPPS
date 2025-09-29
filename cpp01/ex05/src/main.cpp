/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:59:40 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:59:41 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	the_man;

	the_man.complain("DEBUG");
	the_man.complain("");
	the_man.complain("INFO");
	the_man.complain("WARN");
	the_man.complain("WARNING");
	the_man.complain("FO");
	the_man.complain("ERROR");
	return 0;
}
