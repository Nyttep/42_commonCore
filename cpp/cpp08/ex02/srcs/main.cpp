/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:29:08 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/05 19:05:21 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <vector>

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	
	std::vector<int> mvect;
	
	mvect.push_back(5);
	mvect.push_back(17);
	std::cout << mvect.back() << std::endl;
	mvect.pop_back();
	std::cout << mvect.size() << std::endl;
	mvect.push_back(3);
	mvect.push_back(5);
	mvect.push_back(737);
	mvect.push_back(0);
	std::vector<int>::iterator itv = mvect.begin();
	std::vector<int>::iterator itev = mvect.end();
	++itv;
	--itv;
	while (itv != itev)
	{
	std::cout << *itv << std::endl;
	++itv;
	}

	return 0;
}