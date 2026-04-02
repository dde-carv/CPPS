/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:07:40 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/02 14:47:01 by dde-carv         ###   ########.fr       */
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
		std::map<std::string, float>	_db;

		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange	&operator=(const BitcoinExchange &src);

		bool		isLeapYear(int year) const;
		bool		validDate(const std::string &date) const;
		bool		validValue(const std::string &val, float &out) const;
		std::string	trim(const std::string &s) const;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void	loadDataBase(const std::string &fileName);
		void	processInput(const std::string &fileName) const;
};
