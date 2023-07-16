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
		_rate.insert(std::pair<std::string, float>(key, value));
	}
	iFile.close();
	return (0);
}

int	BitcoinExchange::_isValidDate(std::string buffer)
{
	std::string				tmp;
	std::string::iterator	it = buffer.begin();

	it = skipSpaces(it);	
}

int	BitchoinExchange::_isValidInput(std::string buffer)
{
	for (std::string::iterator it = buffer.begin(); it != buffer.end(); it++)
	{
		if (!(std::isdigit(*it) || *it == ' ' || *it == '-' || *it == '|' || *it == '.'))
		{
			std::cerr << "Error: bad input => " << buffer << "\n";
			return (0);
		}
	}
	if (!_isValidDate(buffer))
		return (0);
	//CHECK IN-BETWEEN
	if (!_isValidInput(buffer))
		return (0);
	//check after
	return (1);
}

int	BitcoinExchange::eval(std::string DBAmount)
{
	std::ifstream	iFile;

	iFile.open(DBAmount.c_str);
	if(!iFile.is_open())
	{
		std::cerr << "Error: The file can't be opened because it doesn't exist or you don't have permissions\n";
		return (1);
	}
	std::string	buffer;
	std::string	date;
	std::string	value;
	float		rate;
	while (std::getline(iFile, buffer))
	{
		if (_isValidInput(buffer))
		{
			date = _getDate(buffer);
			value = _getValue(buffer);
			rate = _getRate(date);
			std::cout << date << " => " << value << " = " << rate * value;
		}
		std::cout << std::endl;
	}
}
