/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myFunctions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:40:03 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 18:58:18 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myFunctions.hpp"

Base*	generate()
{
	std::srand(std::time(NULL));
	int	rdm = std::rand() % 3;
	Base*	ret;
	
	if (rdm == 0)
	{
		ret = new A;
		return (ret);
	}
	else if (rdm == 1)
	{
		ret = new B;
		return (ret);
	}
	else
	{
		ret = new C;
		return (ret);
	}
}

void	identify(Base* p)
{
	A* tstA;
	B* tstB;
	C* tstC;
	
	tstA = dynamic_cast<A*>(p);
	tstB = dynamic_cast<B*>(p);
	tstC = dynamic_cast<C*>(p);
	if (tstA != NULL)
		std::cout << "The true type of this object is A" << std::endl;
	else if (tstB != NULL)
		std::cout << "The true type of this object is B" << std::endl;
	else if (tstC != NULL)
		std::cout << "The true type of this object is C" << std::endl;
}

void	identify(Base& p)
{
	A tstA;
	B tstB;
	C tstC;
	
	try
	{
		tstA = dynamic_cast<A&>(p);
		std::cout << "The true type of this object is A" << std::endl;
	}
	catch (std::exception& e){}
	try
	{
		tstB = dynamic_cast<B&>(p);
		std::cout << "The true type of this object is B" << std::endl;
	}
	catch (std::exception& e){}
	try
	{
		tstC = dynamic_cast<C&>(p);
		std::cout << "The true type of this object is C" << std::endl;
	}
	catch (std::exception& e){}
}
