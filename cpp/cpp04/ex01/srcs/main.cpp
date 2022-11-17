/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:34:58 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/16 17:10:30 by pdubois          ###   ########.fr       */
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
	myAnimals[1]->makeSound();
	for (int i = 0; i < 100; i++)
		delete myAnimals[i];
	delete [] myAnimals;
}