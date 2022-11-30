/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myFunctions.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:34:59 by pdubois           #+#    #+#             */
/*   Updated: 2022/11/30 16:49:24 by pdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFUNCTIONS_HPP
# define MYFUNCTIONS_HPP

# include "Data.hpp"
# include <stdint.h>

uintptr_t	serialize(Data*ptr);
Data*	deserialize(uintptr_t raw);

#endif