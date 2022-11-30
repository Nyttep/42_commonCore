/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:26:29 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 16:33:08 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class	Data
{
	private	:
		char	c;
	public :
		Data();
		Data(const Data& toCopy);
		~Data();
		Data&	operator=(const Data& rhs);
};

#endif