/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:06:32 by pdubois           #+#    #+#             */
/*   Updated: 2023/07/09 17:42:45 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <stdlib.h>
# include <iostream>
# include <fstream>
# include <string>
# include <map>

class	BitcoinExchange
{
	private :
		std::map<std::string, float>	_rate;
	public :
		BitcoinExchange();
		BitcoinExchange(std::map<std::string, float> newRate);
		BitcoinExchange(const BitcoinExchange& toCopy);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& toCopy);
		int	init();
		int	eval(std::string DBAmount);

};

#endif 