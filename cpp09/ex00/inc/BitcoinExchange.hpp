/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:07:40 by dde-carv          #+#    #+#             */
/*   Updated: 2025/11/03 15:45:36 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <cmath>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_dataBase;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void		loadDatabase(const std::string &fileName);
		void		processDatabase(const std::string &fileName) const;

	private:
		bool		validDate(const std::string &date);
		std::string	trim(const std::string &str) const;
};
