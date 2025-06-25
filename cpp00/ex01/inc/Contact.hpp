/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:23:36 by dde-carv          #+#    #+#             */
/*   Updated: 2025/06/25 17:15:59 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string.h>
# include <stdlib.h>

class Contact{

	private:
		//* attributes
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string darkest_secret;
		std::string phone_number;

	public:
		//* methods
		std::string	format_field(std::string prompt, int flag);
		std::string	get_input(std::string message, int flag);
		void		validate_number();
		void		display_line();
		void		display_info();
		void		fill_form();
		int			is_empty();

};

# endif
