/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:07:42 by dde-carv          #+#    #+#             */
/*   Updated: 2025/11/04 15:12:24 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_dataBase = other._dataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

bool	BitcoinExchange::validDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (std::size_t i = 0; i < date.size(); i++)
	{
		if ((i == 4) || (i == 7))
			continue ;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
}

void	BitcoinExchange::loadDataBase(const std::string &fileName)
{
	std::ifstream	file(fileName.c_str());
	if (!file.is_open())
			throw std::runtime_error("Error: Cannot open the database file!");

	std::string	line;

	while(std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::size_t	commaPos = line.find(',');

		std::string	dateStr = line.substr(0, commaPos);
		std::string	rateStr = line.substr(commaPos + 1);

		float	rate = std::atof(rateStr.c_str());
		if (!validDate(dateStr) || rate < 0.0f)
			continue ;

		_dataBase[dateStr] = rate;
	}
	file.close();
}
