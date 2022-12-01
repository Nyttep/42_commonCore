/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:22:59 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/01 15:24:06 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//------------------ Constructors & destructors ------------------
template<typename T>
Array::Array()
{
	std::cout << "Array default constructor called" << std::endl;
	_data = new T[0];
}

template<typename T>
Array::Array(const Array<T>& toCopy)
{
	std::cout << "Array copy constructor called" << std::endl;
	*this = toCopy;
}

template<typename T>
Array::Array(size_t n)
{
	std::cout << "Array args constructor called" << std::endl;
	_data = new T[n];
}

template<typename T>
Array::~Array()
{
	std::cout << "Array default destructor called" << std::endl;
	delete [] _data;
}

//-------------------- Operators Overloads ---------------------
template<typename T>
Array<T>&	Array::operator=(const Array<T>& toCopy)
{
	delete [] _data;
	_data = new T[toCopy.size()];
	for (int i = 0; 1; i++)
	{
		try
		{
			_data[i] = toCopy[i];
		}
		catch (std::exception& e)
		{
			return (*this);
		}
	}
}

template<typename T>
T&	Array::operator[](size_t i)
{
	if (i >= size())
		throw std::exception();
	return (_data[i]);
}

//-------------------- Other Functions ----------------------
template<typename T>
size_t	Array::size()
{
	size_t i;
	for (i = 0; _data[i]; i++)
		i++;
	return (i);
}
