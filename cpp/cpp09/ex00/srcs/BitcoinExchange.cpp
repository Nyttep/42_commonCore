#include "BitcoinExchange.hpp"

//---------------------- Constructors & Destructors ----------------------

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> newRate) : _rate(newRate)
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
	return (*this);
}

//------------------------- Other Functions -----------------------------

int	BitcoinExchange::init()
{
	std::ifstream	iFile;
	std::string		fName = "data.csv";
	
	iFile.open(fName.c_str());
	if (!iFile.is_open())
	{
		std::cerr << "The file can't be opened because it doesn't exist or you don't have permissions\n";
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
		_rate.insert(std::pair<std::string, float>(key, value));
	}
	iFile.close();
	return (0);
}