/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:07:40 by dde-carv          #+#    #+#             */
/*   Updated: 2025/11/17 17:23:26 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
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

		void		loadDataBase(const std::string &fileName);
		void		processInput(const std::string &fileName) const;

	private:
		bool		isLeapYear(int year);
		bool		validDate(const std::string &date) const;
		std::string	trim(const std::string &str) const;
};
