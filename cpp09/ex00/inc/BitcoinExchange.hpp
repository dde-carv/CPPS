/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:07:40 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/28 09:40:53 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <cstdlib>
# include <stdexcept>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	importRates(const std::string &csvFile);
		void	evaluateFile(const std::string &inputFile) const;

	private:
		std::map<std::string, double>	_db;

		bool	checkDate(const std::string &date) const;
		bool	parseAmount(const std::string &raw, double &result) const;
		double	findRate(const std::string &date) const;
};
