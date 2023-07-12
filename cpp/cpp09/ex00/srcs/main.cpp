#include "BitcoinExchange.hpp"

int	checkArgs(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cerr << "Program must be called like this :\n./btc <filename>";
		return (1);
	}
	std::string	fName = argv[1];
	if (checkDB(fName) == 1)
		return (1);
	return (0);
}

/*int	checkDB(std::string fName)
{
	std::ifstream	iFile;

	iFile.open(fName.c_str());
	if (!iFile.is_open())
{
		std::cerr << "The file can't be opened because it doesn't exist or you don't have permissions\n";
		return (1);
	}
}*/

int	main(int argc, char** argv)
{

}