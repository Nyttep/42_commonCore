/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:00:41 by pdubois           #+#    #+#             */
/*   Updated: 2023/07/25 08:00:41 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//---------------------- Constructors & Destructors ----------------------

RPN::RPN() : _operators("+-*/")//, _operators[1]('-'), _operators[2]('*'), _operators[3]('/')
{}

RPN::RPN(const RPN& toCopy)
{
	*this = toCopy;
}

RPN::~RPN()
{}

//----------------------- Operators Overloads ---------------------------

RPN&	RPN::operator=(const RPN& toCopy)
{
	_operands = toCopy._operands;
	return (*this);
}

//------------------------------ Exceptions -------------------------------

const char* RPN::OverflowException::what()const throw()
{
	return ("Int overflow");
}

const char* RPN::DivideByZeroException::what()const throw()
{
	return ("Dividing by zero");
}

//------------------------- Other Functions -----------------------------

long int	RPN::_add(const int lhs, const int rhs) const
{
	return (lhs + rhs);
}

long int	RPN::_substract(const int lhs, const int rhs) const
{
	return (lhs - rhs);
}

long int	RPN::_multiply(const int lhs, const int rhs) const
{
	return (lhs * rhs);
}

long int	RPN::_divide(const int lhs, const int rhs) const
{
	if (rhs == 0)
		throw RPN::DivideByZeroException();
	return (lhs / rhs);
}

int	RPN::_operation(const int lhs, const int rhs, const char op) const
{
	int			ret = 0;
	long int	tmpRet = 0;

	if (op == '+')
		tmpRet = _add(lhs, rhs);
	if (op == '-')
		tmpRet = _substract(lhs, rhs);
	if (op == '*')
		tmpRet = _multiply(lhs, rhs);
	if (op == '/')
		tmpRet = _divide(lhs, rhs);
	if (tmpRet > 2147483647 || tmpRet < -2147483648)
		throw RPN::OverflowException();
	else
		ret = tmpRet;
	return (ret);
}

int	RPN::_isOperator(const char c) const
{
	for (int i = 0; i < 4; i++)
	{
		if (c == _operators[i])
			return (1);
	}
	return (0);
}

int	RPN::calculate(const std::string expression, int& result)
{
	int	space = 0;
	int	lhs;
	int	rhs;
	for(std::string::const_iterator it = expression.begin(); it != expression.end(); it++)
	{
		if (space % 2 == 1)
		{
			if (*it != ' ')
			{
				std::cerr << "Error: invalid expression\n";
				return (1);
			}
		}
		if (std::isdigit(*it))
			_operands.push(*it - '0');
		else if (_isOperator(*it))
		{
			if (_operands.size() > 1)
			{
				try
				{
					rhs = _operands.top();
					_operands.pop();
					lhs = _operands.top();
					_operands.pop();
					_operands.push(_operation(lhs, rhs, *it));
				}
				catch (std::exception& e)
				{
					std::cerr << "Error: " << e.what() << "\n";
					return (1);
				}
			}
			else
			{
				std::cerr << "Error: invalid expression\n";
				return (1);
			}
		}
		else if (*it != ' ')
		{
			std::cerr << "Error: invalid expression\n";
			return (1);
		}
		space++;
	}
	if (_operands.size() != 1)
	{
		std::cerr << "Error: invalid expression\n";
		return (1);
	}
	result = _operands.top();
	_operands.pop();
	return (0);
}