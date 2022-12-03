/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:22:13 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/03 18:09:43 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//---------------------- Constructors & Destructors ----------------------
Span::Span() : _max(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(int newMax) : _max(newMax)
{
	std::cout << "Span args constructor called" << std::endl;
}

Span::Span(const Span& toCopy) : _max(toCopy._max)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = toCopy;
}

Span::~Span()
{
	std::cout << "Span default destructor called" << std::endl;
}

//----------------------- Operators Overloads ---------------------------
Span&	Span::operator=(const Span& toCopy)
{
	this->_vect = toCopy._vect;
	return (*this);
}

//------------------------- Other Functions -----------------------------
void	Span::addNumber(int n)
{
	if (_vect.size() < _max)
		_vect.push_back(n);
	else
		throw std::runtime_error("Max size reached cannot add another number");
}

unsigned int	Span::shortestSpan()
{
	if (_vect.size() < 2)
		throw std::runtime_error("there is less than 2 numbers so no span can exist");
	std::sort(_vect.begin(), _vect.end());
	unsigned int	min = std::numeric_limits<unsigned int>::max();
	unsigned int	comp = 0;
	std::vector<int>::iterator iter = _vect.begin();
	for (int i = 0; iter + i + 1 != _vect.end(); i++)
	{
		comp =(_vect[i] - _vect[i + 1]) * -1;
		if (comp < min)
			min = comp;
	}
	return (min);
}

unsigned int	Span::longestSpan()
{
	if (_vect.size() < 2)
		throw std::runtime_error("there is less than 2 numbers so no span can exist");
	std::sort(_vect.begin(), _vect.end());
	unsigned int	min = 0;
	unsigned int	comp = 0;
	std::vector<int>::iterator iter = _vect.begin();
	for (int i = 0; iter + i + 1 != _vect.end(); i++)
	{
		comp =(_vect[i] - _vect[i + 1]) * -1;
		if (comp > min)
			min = comp;
	}
	return (min);
}

void	Span::fillRandom(unsigned int n)
{
	srand(time(0));
	
	while (n > 0)
	{
		this->addNumber(rand());
		n--;
	}
}
