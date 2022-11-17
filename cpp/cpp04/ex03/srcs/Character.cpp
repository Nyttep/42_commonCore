/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:49:56 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 19:03:13 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//---------------------- Constructors & Destructors -------------------
Character::Character() : _name(""), _inventory[0](), _inventory[1](), _inventory[2](), _inventory[3]()
{
	std::cout << "Character default Constructor Called" << std::endl;
}

Character::Character(const Character& to_copy) : _name(to_copy.getName()), _inventory[0](to_copy.getMateria(0)), _inventory[1](to_copy.getMateria(1)), _inventory[2](to_copy.getMateria(2)), _inventory[3](to_copy.getMateria(3))
{
	std::cout << "Character copy Constructor Called" << std::endl;
}

Character::Character(const std::string newName) : _name(newName), _inventory[0](), _inventory[1](), _inventory[2](), _inventory[3]()
{
	std::cout << "Character string Constructor Called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character default Destructor Called" << std::endl;
	for (int i = 0; (i <= 3) || _inventory[i]; i++)
		delete _inventory[i];
	delete [] _inventory;
}

 //------------------- Operators Overload ---------------------------
 
