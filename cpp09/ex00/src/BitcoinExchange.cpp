/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:07:42 by dde-carv          #+#    #+#             */
/*   Updated: 2026/07/30 11:26:12 by dde-carv         ###   ########.fr       */
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

static std::string	trim(const std::string &s)
{
	std::size_t	first = 0;
	std::size_t	last = s.size();

	while (first < last && std::isspace(static_cast<unsigned char>(s[first])))
		first++;
	while (last > first && std::isspace(static_cast<unsigned char>(s[last - 1])))
		last--;
	return s.substr(first, last - first);
}

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

	bool	hasDigit = false;
	bool	hasDot = false;
	std::size_t	i = 0;

	if (raw[i] == '-')
		i++;
	if (i == raw.size())
		return false;
	for (; i < raw.size(); i++)
	{
		if (raw[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(raw[i])))
			hasDigit = true;
		else
			return false;
	}
	if (!hasDigit)
		return false;

	char	*end;
	errno = 0;
	result = std::strtod(raw.c_str(), &end);
	if (*end != '\0' || errno == ERANGE)
		return false;
	if (result != result)
		return false;
	return true;
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return year % 4 == 0;
}

int	BitcoinExchange::daysInMonth(int year, int month) const
{
	static const int	days[] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	if (month == 2 && isLeapYear(year))
		return 29;
	return days[month - 1];
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
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > daysInMonth(year, month))
		return false;
	return true;
}

void	BitcoinExchange::evaluateFile(const std::string &inputFile) const
{
	std::ifstream	file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open input file: " + inputFile);

	std::string	line;
	if (std::getline(file, line) && trim(line) != "date | value")
		throw std::runtime_error("Invalid header: \"" + line + "\" (expected: 'date | value')");
	if (line.empty())
		throw std::runtime_error("Empty input file : " + inputFile);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;

		std::size_t	sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		if (line.find('|', sep + 1) != std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		std::string	date = trim(line.substr(0, sep));
		std::string	amtStr = trim(line.substr(sep + 1));

		if (!checkDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		double	amount;
		if (!parseAmount(amtStr, amount))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (amount < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (amount > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
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
	if (!std::getline(file, line) || trim(line) != "date,exchange_rate")
		throw std::runtime_error("invalid database header.");
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::size_t	sep = line.find(',');
		if (sep == std::string::npos)
			continue ;
		if (line.find(',', sep + 1) != std::string::npos)
			continue ;
		std::string	date = trim(line.substr(0, sep));
		std::string	priceStr = trim(line.substr(sep + 1));
		if (!checkDate(date) || priceStr.empty())
			continue ;
		double		price = std::atof(priceStr.c_str());
		_db[date] = price;
	}
}
