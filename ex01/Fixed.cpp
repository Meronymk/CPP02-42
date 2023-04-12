/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:25:29 by krochefo          #+#    #+#             */
/*   Updated: 2023/04/12 00:21:42 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static	float raiseToPower(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

Fixed::Fixed() : _bit(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const & copy)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_bit = copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (this->_bit);
}

void Fixed::setRawBits( int const raw )
{
	this->_bit = raw;
}

Fixed::Fixed(const int value): _bit(std::roundf(value * raiseToPower(2, this->_rawBit)))
{  
	std::cout << "Int constructor called" << std::endl; 
} 

Fixed::Fixed(const float value): _bit(std::roundf(value * raiseToPower(2, this->_rawBit)))
{  
	std::cout << "Float constructor called" << std::endl; 
} 

float Fixed::toFloat( void ) const
{
	return (this->_bit * raiseToPower(2, -this->_rawBit));
}

int Fixed::toInt( void ) const
{
	return (this->_bit * raiseToPower(2, -this->_rawBit));
}

std::ostream &operator<<(std::ostream &out, const Fixed &rightHandSide)
{
	return (out << rightHandSide.toFloat());
}