/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:17:05 by pdubois           #+#    #+#             */
/*   Updated: 2023/08/06 17:17:05 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//---------------------- Constructors & Destructors ----------------------

PmergerMe::PmergeMe()
{}

PmergeMe::PmergeMe(char** toSort) //MOOVE THIS TO sort()
{
	std::vector<unsigned int>::iterator	itVect = _sortVect.end();
	std::deque<unsigned int>::iterator	itDeque = _sortDeque.end();
	for (unsigned int i = 0; toSort[i]; i++)
	{
		_sortVect.insert(itVect, atol(toSort[i]));
		_sortDeque.insert(itDeque, atol(toSort[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe& toCopy)
{
	*this = toCopy;
}

PmergeMe::~PmergeMe()
{}
