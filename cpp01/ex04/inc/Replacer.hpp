/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:59:09 by dde-carv          #+#    #+#             */
/*   Updated: 2025/09/29 16:59:10 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string.h>

class Replacer
{
	private:
		std::fstream	_oldfile;
		std::fstream	_newfile;
	public:
		Replacer();
		~Replacer();
		void	file_closer();
		int		set_new_file(std::string fname);
		int		replace(std::string s1, std::string s2);
};
