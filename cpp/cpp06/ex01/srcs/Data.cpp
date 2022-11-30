/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:29:01 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 16:49:36 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data(const Data& toCopy)
{
	*this = toCopy;
	std::cout << "Data copy constructor called" << std::endl;
}

Data::~Data()
{
	std::cout << "Data default destructor called" << std::endl;
}

Data&	Data::operator=(const Data& rhs)
{
	this->c = rhs.c;
	return (*this);
}
