/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:59:54 by pdubois           #+#    #+#             */
/*   Updated: 2022/09/27 17:26:14 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
{
	this->type = newType;
	return ;
}

const std::string&	Weapon::getType(void)
{
	const std::string&	ret = this->type;
	return (ret);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
	return ;
}
