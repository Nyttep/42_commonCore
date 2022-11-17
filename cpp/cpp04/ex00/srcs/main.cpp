/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:34:58 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 15:21:28 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	const WrongAnimal* Wrongmeta = new WrongAnimal();
	const WrongAnimal* Wrongi = new WrongCat();

	std::cout << Wrongi->getType() << " " << std::endl;
	Wrongi->makeSound();
	std::cout << Wrongmeta->getType() << " " << std::endl;
	Wrongmeta->makeSound();
	delete Wrongmeta;
	delete Wrongi;
	return 0;
}