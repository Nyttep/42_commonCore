/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:01:10 by pdubois           #+#    #+#             */
/*   Updated: 2023/07/25 08:01:10 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//---------------------- Constructors & Destructors ----------------------

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> newRate) : _DBrate(newRate)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy)
{
	*this = toCopy;
}

BitcoinExchange::~BitcoinExchange()
{}

//----------------------- Operators Overloads ---------------------------

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& toCopy)
{
	_DBrate = toCopy._DBrate;
	return (*this);
}

// ------------- Setters & Getters ---------------------

std::string	BitcoinExchange::_getDate(std::string buffer)
{
	std::string	date;
	int			i = 0;
	
	while (buffer[i] == ' ')
		i++;
	date = buffer.substr(i, 10);
	return (date);
}

float	BitcoinExchange::_getValue(std::string buffer)
{
	float	value;
	int	i = buffer.size() - 1;

	while (buffer[i] == ' ')
		i--;
	while (buffer[i] == '.' || std::isdigit(buffer[i]))
		i--;
	value = atof(&(buffer[i]));
	return (value);
}

float	BitcoinExchange::_getRate(std::string date)
{
	float	rate;
	int		found;

	found = _DBrate.count(date);
	if (found == 1)
	{
		rate = _DBrate[date];
		return (rate);
	}
	date = _findLowerDate(date);
	rate = _DBrate[date];
	return (rate);
}

//------------------------- Other Functions -----------------------------

int	BitcoinExchange::init()
{
	std::ifstream	iFile;
	std::string		fName = "data.csv";
	
	iFile.open(fName.c_str());
	if (!iFile.is_open())
	{
		std::cerr << "Error: The file can't be opened because it doesn't exist or you don't have permissions\n";
		return (1);
	}
	std::string	buffer;
	std::string	key;
	float	value;
	std::getline(iFile, buffer);
	while (std::getline(iFile, buffer))
	{
		key = buffer.substr(0, 10);
		value = atof(buffer.substr(11, buffer.size() - 1).c_str());
		_DBrate.insert(std::pair<std::string, float>(key, value));
	}
	iFile.close();
	return (0);
}

int	BitcoinExchange::_isValidDate(std::string::iterator &it, std::string buffer)
{
	std::string				nbr;
	int						year;
	int						month;
	int						day;

	while (*it == ' ')
		it++;
	year = atoi(&*it);
	if (year < 2009 || year > 2023)
	{
		std::cerr << "Error: invalid year => " << buffer << "\n";
		return (0);
	}
	it += 4;
	if (*it != '-')
	{
		std::cerr << "Error: bad input => " << buffer << "\n";
		return (0);
	}
	it++;
	month = atoi(&*it);
	if (month < 1 || month > 12)
	{
		std::cerr << "Error: invalid month => " << buffer << "\n";
		return (0);
	}
	it += 2;
	if (*it != '-')
	{
		std::cerr << "Error: bad input => " << buffer << "\n";
		return (0);
	}
	it++;
	day = atoi(&*it);
	if (month == 2) //february
	{
		if (year % 4 == 0) //leap years
		{
			if (day < 1 || day > 29)
			{
				std::cerr << "Error: invalid day => " << buffer << "\n";
				return (0);
			}
		}
		else
		{
			if (day < 1 || day > 28)
			{
				std::cerr << "Error: invalid day => " << buffer << "\n";
				return (0);
			}
		}
	}
	else if (month % 2 == 0)
	{
		if (day < 1 || day > 30)
		{
			std::cerr << "Error: invalid day => " << buffer << "\n";
			return (0);
		}
	}
	else
	{
		if (day < 1 || day > 31)
		{
			std::cerr << "Error: invalid day => " << buffer << "\n";
			return (0);
		}
	}
	if (year == 2009 && month == 1 && day == 1)
	{
		std::cerr << "Error: no valid rate in database for this date => " << buffer << "\n";
		return (0);
	}
	it += 2;
	return (1);
}

int	BitcoinExchange::_isValidValue(std::string::iterator &it, std::string buffer)
{
	float	value;

	while (*it == ' ')
		it++;
	value = atof(&*it);
	if (value < 0)
	{
		std::cerr << "Error: not a positive number => " << buffer << "\n"; 
		return (0);
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number => " << buffer << "\n"; 
		return (0);
	}
	while (std::isdigit(*it))
		it++;
	if (*it == '.')
		it++;
	while (std::isdigit(*it))
		it++;
	return (1);
}

int	BitcoinExchange::_isValidInput(std::string buffer)
{
	for (std::string::iterator it = buffer.begin(); it != buffer.end(); it++)
	{
		if (!(std::isdigit(*it) || std::isspace(*it) || *it == '-' || *it == '|' || *it == '.'))
		{
			std::cerr << "Error: bad input => " << buffer << "\n";
			return (0);
		}
	}
	std::string::iterator	it = buffer.begin();
	if (!_isValidDate(it, buffer))
		return (0);
	while (*it == ' ')
		it++;
	if (*it != '|')
	{
		std::cerr << "Error: bad input => " << buffer << "\n";
		return (0);
	}
	it++;
	if (!_isValidValue(it, buffer))
		return (0);
	while (*it == ' ')
		it++;
	if (it != buffer.end())
	{
		std::cerr << "Error : bad input => " << buffer << "\n";
		return (0);
	}
	return (1);
}

int	BitcoinExchange::eval(std::string DBAmount)
{
	std::ifstream	iFile;

	iFile.open(DBAmount.c_str());
	if(!iFile.is_open())
	{
		std::cerr << "Error: The file can't be opened because it doesn't exist or you don't have permissions\n";
		return (1);
	}
	std::string	buffer;
	std::string	date;
	float	value;
	float		rate;
	while (std::getline(iFile, buffer))
	{
		if (_isValidInput(buffer))
		{
			date = _getDate(buffer);
			value = _getValue(buffer);
			rate = _getRate(date);
			std::cout << date << " => " << value << " = " << rate * value;
			std::cout << std::endl;
		}
	}
	return (0);
}

std::string	BitcoinExchange::_findLowerDate(std::string date)
{
	std::ostringstream		ss;
	int						year;
	int						month;
	int						day;

	ss << std::setfill('0');
	while (_DBrate.count(date) == 0)
	{
		year = atof(&(date[0]));
		month = atof(&(date[5]));
		day = atof(&(date[8]));
		if (day == 1)
		{
			if (month == 3)
			{
				date[8] = '2';
				if (year % 4 == 0)
					date[9] = '9';
				else
					date[9] = '8';
			}
			else if (month == 1)
			{
				ss << std::setw(2) << year - 2001;
				date[2] = ss.str()[0];
				date[3] = ss.str()[1];
				date[5] = '1';
				date[6] = '2';
				date[8] = '3';
				date[9] = '1';
				ss.str("");
				ss.clear();
			}
			else if ((month % 2 == 0 && month < 7) || (month % 2 == 1 && month > 8))
			{
				date[8] = '3';
				date[9] = '0';
			}
			else
			{
				date[8] = '3';
				date[9] = '1';
			}
		}
		else
		{
			ss << std::setw(2) << (day - 1);
			//std::cout << "LOOP ss : " << ss.str() << std::endl;
			date[8] = ss.str()[0];
			date[9] = ss.str()[1];
			ss.str("");
			ss.clear();
		}
	}
	return (date);
}