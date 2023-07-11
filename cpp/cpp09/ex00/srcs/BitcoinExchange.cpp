#include "BitcoinExchange.hpp"

//---------------------- Constructors & Destructors ----------------------

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> newRate, std::map<std::string, float> newAmount) : _rate(newRate), _amount(newAmount)
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
	_rate = toCopy._rate;
	_amount = toCopy._amount;
	return (*this);
}