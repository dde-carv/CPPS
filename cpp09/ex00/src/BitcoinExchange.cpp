/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:07:42 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/28 15:19:06 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

double	BitcoinExchange::findRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator	it = _db.upper_bound(date);
	if (it == _db.begin())
		throw std::runtime_error("no rate available for date: " + date);
	--it;
	return it->second;
}

bool	BitcoinExchange::parseAmount(const std::string &raw, double &result) const
{
	if (raw.empty())
		return false;
	char	*end;
	result = std::strtod(raw.c_str(), &end);
	if (*end != '\0')
		return false;
	if (result != result)
		return false;
	return true;
}

bool	BitcoinExchange::checkDate(const std::string &date) const
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue ;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day   = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
}

void	BitcoinExchange::evaluateFile(const std::string &inputFile) const
{
	std::ifstream	file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open input file: " + inputFile);

	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::size_t	sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = line.substr(0, sep);
		std::string	amtStr = line.substr(sep + 1);

		while (!date.empty() && date[0] == ' ')
			date.erase(0, 1);
		while (!date.empty() && date[date.size() - 1] == ' ')
			date.erase(date.size() - 1);
		while (!amtStr.empty() && amtStr[0] == ' ')
			amtStr.erase(0, 1);
		while (!amtStr.empty() && amtStr[amtStr.size() - 1] == ' ')
			amtStr.erase(amtStr.size() - 1);

		if (!checkDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double	amount;
		if (!parseAmount(amtStr, amount))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (amount < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (amount > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			double	rate = findRate(date);
			std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

void	BitcoinExchange::importRates(const std::string &csvFile)
{
	std::ifstream	file(csvFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open database: " + csvFile);

	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::size_t	sep = line.find(',');
		if (sep == std::string::npos)
			continue ;
		std::string	date = line.substr(0, sep);
		std::string	priceStr = line.substr(sep + 1);
		double		price = std::atof(priceStr.c_str());
		_db[date] = price;
	}
}
