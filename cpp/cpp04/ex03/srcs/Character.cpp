/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:49:56 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/18 18:15:24 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//---------------------- Constructors & Destructors -------------------
Character::Character() : _name("")
{
	std::cout << "Character default Constructor Called" << std::endl;
	_inventory = new AMateria*[4];
	for (int i = 0; i <= 3; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& to_copy) : _name(to_copy.getName())
{
	std::cout << "Character copy Constructor Called" << std::endl;
	_inventory = new AMateria*[4];
	for (int i = 0; (i <= 3) && to_copy._inventory[i]; i++)
		_inventory[i] = to_copy._inventory[i]->clone();
}

Character::Character(const std::string newName) : _name(newName)
{
	std::cout << "Character string Constructor Called" << std::endl;
	_inventory = new AMateria*[4];
	for (int i = 0; i <= 3; i++)
		_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character default Destructor Called" << std::endl;
	for (int i = 0; (i <= 3) && _inventory[i]; i++)
		delete _inventory[i];
	delete [] _inventory;
}

 //------------------- Operators Overload ---------------------------
Character&	Character::operator=(const Character& rhs)
{
	for (int i = 0; (i <= 3); i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		this->_inventory[i] = rhs._inventory[i]->clone();
	}
	this->_name = rhs._name;
	return (*this);
}

//------------------ Setters & Getters -----------------------------
const std::string& Character::getName() const
{
	return (_name);
}

AMateria*	Character::getMateria(int idx) const
{
	return (_inventory[idx]);
}

//------------------- Others Functions ------------------------------
void	Character::equip(AMateria* m)
{
	int	i = 0;
	
	while (_inventory[i] && i < 3)
		i++;
	if (i == 3)
		return ;
	_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	int	i = 0;
	
	if (idx > 3 || idx < 0)
		return ;
	while (_inventory[i] && i < 3)
		i++;
	while (idx < i)
	{
		_inventory[idx] = _inventory[idx + 1];
		idx++;
	}
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	_inventory[idx]->use(target);
}
