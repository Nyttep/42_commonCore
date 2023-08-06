/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:00:50 by pdubois           #+#    #+#             */
/*   Updated: 2023/07/25 08:00:50 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <stdlib.h>
# include <stdexcept>
# include <iostream>

class RPN
{
private:
	std::stack<int>	_operands;
	std::string		_operators;
	long int		_add(const int lhs, const int rhs) const;
	long int		_substract(const int lhs, int const rhs) const;
	long int		_multiply(const int lhs, const int rhs) const;
	long int		_divide(const int lhs, const int rhs) const;
	int 			_operation(const int lhs, const int rhs, const char op) const;
	int				_isOperator(const char c) const;
	class	OverflowException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	class	DivideByZeroException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
public:
	RPN();
	RPN(const RPN& toCopy);
	~RPN();
	RPN& operator=(const RPN& toCopy);
	int	calculate(const std::string expression, int& result);
};


#endif