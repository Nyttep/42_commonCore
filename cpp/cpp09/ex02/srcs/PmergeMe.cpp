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

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(char** toSort)
{
	int	tmp = 0;
	for (unsigned int i = 0; toSort[i]; i++)
	{
		tmp = atoi(toSort[i]);
		_sortVect.push_back(tmp);
		_sortDeque.push_back(tmp);
	}
	_odd = false;
	_unpaired = 0;
	_sortedVect = 0;
	_sortedDeque = 0;
}

PmergeMe::PmergeMe(const PmergeMe& toCopy)
{
	*this = toCopy;
}

PmergeMe::~PmergeMe()
{}

//----------------------- Operators Overloads ---------------------------

PmergeMe&	PmergeMe::operator=(const PmergeMe& toCopy)
{
	_sortVect = toCopy._sortVect;
	_sortDeque = toCopy._sortDeque;
	_odd = toCopy._odd;
	_unpaired = toCopy._unpaired;
	return (*this);
}

//------------------------- Other Functions -----------------------------

void	PmergeMe::printUnsorted()
{
	if (!_sortedVect)
	{
		std::cout << "Before: ";
		for (std::vector<int>::iterator it = _sortVect.begin(); it != _sortVect.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else if (!_sortedDeque)
	{
		std::cout << "Before: ";
		for (std::deque<int>::iterator it = _sortDeque.begin(); it != _sortDeque.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cerr << "Error: already sorted\n";
	}
}

void	PmergeMe::printSorted()
{
	if (_sortedVect)
	{
		std::cout << "After:  ";
		for (std::vector<int>::iterator it = _sortVect.begin(); it != _sortVect.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else if (_sortedDeque)
	{
		std::cout << "After:  ";
		for (std::deque<int>::iterator it = _sortDeque.begin(); it != _sortDeque.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cerr << "Error: not sorted\n";
	}
}

bool	PmergeMe::_isOdd(int n)
{
	return (n % 2);
}

std::vector<unsigned int>	PmergeMe::_createSeqVect(unsigned int size)
{
	std::vector<unsigned int>	ret;
	unsigned int				nb = 1;
	unsigned int				before = 1;
	unsigned int				tmp = 0;

	while (nb < size)
	{
		ret.push_back(nb);
		for (unsigned int i = nb - 1; i > before; i--)
			ret.push_back(i);
		tmp = nb;
		nb = nb + (before * 2);
		before = tmp;
	}
	while (size > before)
	{
		ret.push_back(size);
		size--;
	}
	return (ret);
}

std::vector<std::vector<int> >	PmergeMe::_createSortedPairsVect()
{
	std::vector<std::vector<int> >	ret;
	std::vector<int>				tmp;
	int								size = _sortVect.size();

	for (int i = 0; i < size; i++)
	{
		tmp.push_back(_sortVect[i]);
		if (tmp.size() == 2)
		{
			if (tmp[0] > tmp[1])
				std::swap(tmp[0], tmp[1]);
			ret.push_back(tmp);
			tmp.clear();
		}
	}
	return (ret);
}

void	PmergeMe::_insertionSortPairsVect(std::vector<std::vector<int> > &pairs, unsigned int size)
{
	if (size <= 1)
		return ;
	_insertionSortPairsVect(pairs, size - 1);
	std::vector<int>	toIns = pairs[size - 1];
	int	i = size - 2;
	while (i >= 0 && pairs[i][1] > toIns[1])
	{
		pairs[i + 1] = pairs[i];
		i--;
	}
	pairs[i + 1] = toIns;
}

std::vector<int>::iterator	PmergeMe::_binSearchVect(unsigned int range, int value)
{
	std::vector<int>::iterator	it = _sortVect.begin();

	it += range / 2;
	while (range > 0)
	{
		range = range /  2;
		if (it < _sortVect.begin() || value > *it)
			it += (range / 2) + 1;
		else
			it -= (range / 2) + 1;
	}
	if (it < _sortVect.begin() || value > *it)
		it++;
	return (it);
}

void	PmergeMe::_mergeVect(std::vector<unsigned int> mergeSeq, std::vector<std::vector<int> > pairs)
{
	unsigned int				i = 1;
	std::vector<int>::iterator	pos;

	if (pairs.size() > 1)
	{
		for (std::vector<unsigned int>::iterator it = mergeSeq.begin() + 1; it != mergeSeq.end(); it++,i++)
		{
			pos = _binSearchVect(std::find(_sortVect.begin(), _sortVect.end(), pairs[*it - 1][1]) - _sortVect.begin(), pairs[*it - 1][0]);
			_sortVect.insert(pos, pairs[*it - 1][0]);
		}
	}
	if (_odd)
		_sortVect.insert(_binSearchVect(_sortVect.size(), _unpaired), _unpaired);
}

void	PmergeMe::sortVect()
{
	if (_isOdd(_sortVect.size()))
	{
		_odd = true;
		_unpaired = _sortVect.back();
		_sortVect.pop_back();
	}
	std::vector<std::vector<int> > pairs = _createSortedPairsVect();
	_insertionSortPairsVect(pairs, pairs.size());
	_sortVect.clear();
	if (!pairs.empty())
	{
		for (std::vector<std::vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
			_sortVect.push_back((*it)[1]);
		_sortVect.insert(_sortVect.begin(), pairs[0][0]);
	}
	std::vector<unsigned int>	mergeSeq = _createSeqVect(pairs.size());
	_mergeVect(mergeSeq, pairs);
	_sortedVect = 1;
}

std::deque<unsigned int>	PmergeMe::_createSeqDeque(unsigned int size)
{
	std::deque<unsigned int>	ret;
	unsigned int				nb = 1;
	unsigned int				before = 1;
	unsigned int				tmp = 0;

	while (nb < size)
	{
		ret.push_back(nb);
		for (unsigned int i = nb - 1; i > before; i--)
			ret.push_back(i);
		tmp = nb;
		nb = nb + (before * 2);
		before = tmp;
	}
	while (size > before)
	{
		ret.push_back(size);
		size--;
	}
	return (ret);
}

std::deque<std::deque<int> >	PmergeMe::_createSortedPairsDeque()
{
	std::deque<std::deque<int> >	ret;
	std::deque<int>					tmp;
	int								size = _sortDeque.size();
	for (int i = 0; i < size; i++)
	{
		tmp.push_back(_sortDeque[i]);
		if (tmp.size() == 2)
		{
			if (tmp[0] > tmp[1])
				std::swap(tmp[0], tmp[1]);
			ret.push_back(tmp);
			tmp.clear();
		}
	}
	return (ret);
}

void	PmergeMe::_insertionSortPairsDeque(std::deque<std::deque<int> > &pairs, unsigned int size)
{
	if (size <= 1)
		return ;
	_insertionSortPairsDeque(pairs, size - 1);
	std::deque<int>	toIns = pairs[size - 1];
	int	i = size - 2;
	while (i >= 0 && pairs[i][1] > toIns[1])
	{
		pairs[i + 1] = pairs[i];
		i--;
	}
	pairs[i + 1] = toIns;
}

std::deque<int>::iterator	PmergeMe::_binSearchDeque(unsigned int range, int value)
{
	std::deque<int>::iterator	it = _sortDeque.begin();

	it += range / 2;
	while (range > 0)
	{
		range = range /  2;
		if (it < _sortDeque.begin() || value > *it)
			it += (range / 2) + 1;
		else
			it -= (range / 2) + 1;
	}
	if (it < _sortDeque.begin() || value > *it)
		it++;
	return (it);
}

void	PmergeMe::_mergeDeque(std::deque<unsigned int> mergeSeq, std::deque<std::deque<int> > pairs)
{
	unsigned int				i = 1;
	std::deque<int>::iterator	pos;

	if (pairs.size() > 1)
	{
		for (std::deque<unsigned int>::iterator it = mergeSeq.begin() + 1; it != mergeSeq.end(); it++,i++)
		{
			pos = _binSearchDeque(std::find(_sortDeque.begin(), _sortDeque.end(), pairs[*it - 1][1]) - _sortDeque.begin(), pairs[*it - 1][0]);
			_sortDeque.insert(pos, pairs[*it - 1][0]);
		}
	}
	if (_odd)
		_sortDeque.insert(_binSearchDeque(_sortDeque.size(), _unpaired), _unpaired);
}

void	PmergeMe::sortDeque()
{
	if (_isOdd(_sortDeque.size()))
	{
		_odd = true;
		_unpaired = _sortDeque.back();
		_sortDeque.pop_back();
	}
	std::deque<std::deque<int> > pairs = _createSortedPairsDeque();
	_insertionSortPairsDeque(pairs, pairs.size());
	_sortDeque.clear();
	if (!pairs.empty())
	{
		for (std::deque<std::deque<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
			_sortDeque.push_back((*it)[1]);
		_sortDeque.push_front(pairs[0][0]);
	}
	std::deque<unsigned int>	mergeSeq = _createSeqDeque(pairs.size());
	_mergeDeque(mergeSeq, pairs);
	_sortedDeque = 1;
}