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

# include <map>
# include <string>

class RPN
{
private:
	std::stack<int>	_operands;
	char			_operators[4];
	int				_add(int lhs, int rhs);
	int				_substract(int lhs, int rhs);
	int				_divide(int lhs, int rhs);
	int				_multiply(int lhs, int rhs);
public:
	RPN();
	RPN(const RPN& toCopy);
	~RPN();
	RPN& operator=(const RPN& toCopy);
	calculate(int lhs, int rhs, char op);
};


#endif