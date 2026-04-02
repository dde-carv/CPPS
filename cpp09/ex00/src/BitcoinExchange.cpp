/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:07:42 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/02 14:55:49 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		_db = src._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::loadDataBase(const std::string &fileName)
{
	std::ifstream	file(fileName.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open the database file.");

	std::string	line;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;

		std::size_t	sep = line.find(',');
		if (sep == std::string::npos)
			continue ;

		std::string	date = line.substr(0, sep);
		std::string	rateStr = line.substr(sep + 1);
		float		rate = static_cast<float>(std::atof(rateStr.c_str()));

		if (validDate(date) && rate >= 0.0f)
			_db[date] = rate;
	}
}

void	BitcoinExchange::processInput(const std::string &fileName) const
{
	std::ifstream	infile(fileName.c_str());

	if (!infile.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string	line;
	if (!std::getline(infile, line))
		throw std::runtime_error("Empty input file!");
	if (line != "date | value")
		throw std::runtime_error("Error: first line must be 'date | value'.");

	while (std::getline(infile, line))
	{
		if (line.empty())
			continue ;

		std::size_t	pipePos = line.find(" | ");
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: no pipe symbol => " << line << " '( | ) not found'" << std::endl;
			continue ;
		}

		std::string	date = trim(line.substr(0, pipePos));
		std::string	valueStr = trim(line.substr(pipePos + 3));

		if (!validDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}

		float	value;
		if (!validValue(valueStr, value))
			continue ;

		std::map<std::string, float>::const_iterator	it = _db.lower_bound(date);
		if (it == _db.end() || it->first != date)
		{
			if (it == _db.begin())
			{
				std::cout << "Error: date too early => " << date << std::endl;
				continue ;
			}
			--it;
		}

		float	result = value * it->second;
		if (result == 0.0f)
			result = std::fabs(result);

		std::cout << date << " => " << valueStr << " = " << result << std::endl;
	}
}

bool	BitcoinExchange::validValue(const std::string &val, float &out) const
{
	if (val.empty() || val == ".")
	{
		std::cout << "Error: invalid format => " << val << std::endl;
		return false;
	}
	if (val[0] == '-')
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}

	int	dots = 0;
	for (std::size_t i = 0; i < val.size(); i++)
	{
		if (val[i] == '.')
			dots++;
		else if (!std::isdigit(static_cast<unsigned char>(val[i])))
		{
			std::cout << "Error: invalid number => " << val << std::endl;
			return false;
		}
	}
	if (dots > 1)
	{
		std::cout << "Error: invalid format => " << val << std::endl;
		return false;
	}

	out = static_cast<float>(std::atof(val.c_str()));
	if (out > 1000.0f)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool	BitcoinExchange::validDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (std::size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int	year  = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day   = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;

	int	daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[2] = 29;

	return day <= daysInMonth[month];
}

std::string	BitcoinExchange::trim(const std::string &s) const
{
	std::size_t	start = 0;
	std::size_t	end = s.size();

	while (start < end && std::isspace(static_cast<unsigned char>(s[start])))
		start++;
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		end--;
	return s.substr(start, end - start);
}
