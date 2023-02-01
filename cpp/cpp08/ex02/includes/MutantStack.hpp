/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:49:04 by pdubois           #+#    #+#             */
/*   Updated: 2022/12/08 17:17:51 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <vector>
# include <stdexcept>

template<typename T>
class	MutantStack : public std::stack<T>
{
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		MutantStack()
		{
			std::cout << "MutantStack default constructor called" << std::endl;
		}
		
		MutantStack(const MutantStack& toCopy) : std::stack<T>(toCopy)
		{
			*this = toCopy;
			std::cout << "MutantStack copy constructor called" << std::endl;
		}
		
		~MutantStack()
		{
			std::cout << "MutantStack default destructor called" << std::endl;
		}

		MutantStack&	operator=(const MutantStack& toCopy)
		{
			std::stack<T>::operator=(toCopy);	
			return (*this);
		}
		
		// T&	operator[](int idx)
		// {
		// 	std::vector<T*>	tmp;
			
		// 	for (int i = std::stack<T>::size() - 1 - idx; i > 0; i--)
		// 	{
		// 		tmp.push_back(&(std::stack<T>::top()));
		// 		std::stack<T>::pop();
		// 	}
		// 	T&	ret = std::stack<T>::top();
		// 	while (tmp.size() != 0)
		// 	{
		// 		std::stack<T>::push(*(tmp.back()));
		// 		tmp.pop_back();
		// 	}
		// 	if (std::stack<T>::empty())
		// 		throw std::runtime_error("the stack is empty");
		// 	return (ret);
		// }
		
		// T	operator[](int idx) const
		// {
		// 	std::vector<T>	tmp;
			
		// 	for (int i = std::stack<T>::size() - 1 - idx; i >= 0; i--)
		// 	{
		// 		tmp.push_back(std::stack<T>::top());
		// 		std::stack<T>::pop();
		// 	}
		// 	T&	ret = std::stack<T>::top();
		// 	while (tmp.size() != 0)
		// 	{
		// 		std::stack<T>::push(tmp.back());
		// 		tmp.pop_back();
		// 	}
		// 	if (std::stack<T>::empty())
		// 		throw std::runtime_error("the stack is empty");
		// 	return (ret);
		// }

		T&	operator[](const int idx)
		{
			return (*(this->begin() + idx));
		}	

		T	operator[](const int idx) const
		{
			return (*(this->begin() + idx));
		}	

		iterator begin()
		{
			return(std::stack<T>::c.begin());
		}
		
		const_iterator begin() const
		{
			return(std::stack<T>::c.begin());
		}
		
		iterator end()
		{
			return(std::stack<T>::c.end());
		}

		const_iterator end() const
		{
			return(std::stack<T>::c.end());
		}

		reverse_iterator rbegin()
		{
			return(std::stack<T>::c.rbegin());
		}

		const_reverse_iterator rbegin() const
		{
			return(std::stack<T>::c.rbegin());
		}

		reverse_iterator rend()
		{
			return(std::stack<T>::c.rend());
		}

		const_reverse_iterator rend() const
		{
			return(std::stack<T>::c.rend());
		}

};

#endif