/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:16:56 by pdubois           #+#    #+#             */
/*   Updated: 2023/08/06 17:16:56 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <cstring>
# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include <algorithm>
# include <ctime>
# include <cctype>

class	PmergeMe
{
	private:
		std::vector<int>				_sortVect;
		std::deque<int>					_sortDeque;
		bool							_odd;
		int								_unpaired;
		bool							_sortedVect;
		bool							_sortedDeque;
		bool							_isOdd(int n);
		std::vector<unsigned int>		_createSeqVect(unsigned int size);
		std::vector<std::vector<int> >	_createSortedPairsVect();
		void							_insertionSortPairsVect(std::vector<std::vector<int> > &pairs, unsigned int size);
		void							_mergeVect(std::vector<unsigned int> mergeSeq, std::vector<std::vector<int> > pairs);
		std::vector<int>::iterator		_binSearchVect(unsigned int range, int value);
		std::deque<unsigned int>		_createSeqDeque(unsigned int size);
		std::deque<std::deque<int> >	_createSortedPairsDeque();
		void							_insertionSortPairsDeque(std::deque<std::deque<int> > &pairs, unsigned int size);
		std::deque<int>::iterator		_binSearchDeque(unsigned int range, int value);
		void							_mergeDeque(std::deque<unsigned int> mergeSeq, std::deque<std::deque<int> > pairs);
	public:
		PmergeMe();
		PmergeMe(char** toSort);
		PmergeMe(const PmergeMe& toCopy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& toCopy);
		void		sortVect();
		void		sortDeque();
		void		printUnsorted();
		void		printSorted();
};

#endif