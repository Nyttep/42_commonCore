/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:53:57 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 16:29:54 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//-------------------- Constructors & Destructors --------------------
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default Constructor Called" << std::endl;
	_inventory = new AMateria*[4];
	for (int i = 0; i <= 3; i++)
		_inventory[i] = NULL;
}


MateriaSource::MateriaSource(const MateriaSource& toCopy)
{
	std::cout << "MateriaSource copy Constructor Called" << std::endl;
	_inventory = new AMateria*[4];
	for (int i = 0; (i <= 3) && toCopy._inventory[i]; i++)
		_inventory[i] = toCopy._inventory[i]->clone();
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource default Destructor Called" << std::endl;
	for (int i = 0; (i <= 3) && _inventory[i]; i++)
		delete _inventory[i];
	delete [] _inventory;
}

//------------------- Operators Overload ---------------------------
MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	for (int i = 0; (i <= 3); i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return (*this);
}


//------------------ Setters & Getters -----------------------------
AMateria*	MateriaSource::getMateria(int idx) const
{
	return (_inventory[idx]);
}

//----------------- Other Functions --------------------------------
void	MateriaSource::learnMateria(AMateria* toLearn)
{
	int	i = 0;
	
	while (_inventory[i] && i < 3)
		i++;
	if (i == 3)
		return ;
	_inventory[i] = toLearn->clone();
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i <= 3; i++)
	{
		if (_inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (0);
}
