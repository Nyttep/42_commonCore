/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:34:58 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/17 12:05:07 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	int	n = 100;
	Animal**	myAnimals = new Animal*[n];
	
	for (int i = 0; i < (n / 2); i++)
		myAnimals[i] = new Cat;
	for (int i = (n / 2); i < n; i++)
		myAnimals[i] = new Dog;
	myAnimals[0]->makeSound();
	myAnimals[80]->makeSound();
	for (int i = 0; i < 100; i++)
	{
		if (i % 3 == 0)
			myAnimals[0]->getBrain()->setIdea("I should take a nap !\n", i);
		else if (i % 3 == 1)
			myAnimals[0]->getBrain()->setIdea("I should ask my human to pet me !\n", i);
		else
			myAnimals[0]->getBrain()->setIdea("I should eat !\n", i);
	}
	for (int i = 0; i < 100; i++)
	{
		if (i % 3 == 0)
			myAnimals[80]->getBrain()->setIdea("I should take a nap !\n", i);
		else if (i % 3 == 1)
			myAnimals[80]->getBrain()->setIdea("I should ask my human to pet me !\n", i);
		else
			myAnimals[80]->getBrain()->setIdea("I should eat !\n", i);
	}
	for (int i = 0; i < 100; i++)
	{
		std::cout << myAnimals[0]->getType() << " says " << myAnimals[0]->getBrain()->getIdea(i);
	}
	for (int i = 0; i < 100; i++)
	{
		std::cout << myAnimals[80]->getType() << " says " << myAnimals[80]->getBrain()->getIdea(i);
	}
	std::cout << std::flush;
	for (int i = 0; i < 100; i++)
		delete myAnimals[i];
	delete [] myAnimals;
}