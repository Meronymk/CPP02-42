/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:25:18 by krochefo          #+#    #+#             */
/*   Updated: 2023/04/11 22:20:00 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed{
private:
	int _bit;
	static const int _rawBit = 8;
public:
	Fixed();
	Fixed( Fixed const & copy );
	Fixed &operator=(Fixed const & copy);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif