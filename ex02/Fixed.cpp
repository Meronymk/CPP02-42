/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:25:29 by krochefo          #+#    #+#             */
/*   Updated: 2023/04/12 00:23:41 by krochefo         ###   ########.fr       */
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

Fixed::Fixed() : _bit(0){}
Fixed::~Fixed(){}

Fixed::Fixed( Fixed const & copy )
{
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const & copy)
{
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

Fixed::Fixed(const int value): _bit(std::roundf(value * raiseToPower(2, this->_rawBit))){} 

Fixed::Fixed(const float value): _bit(std::roundf(value * raiseToPower(2, this->_rawBit))){} 

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

int Fixed::operator>( Fixed const & rightHandSide) const
{
	if (this->getRawBits() > rightHandSide.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<( Fixed const & rightHandSide) const
{
	if (this->getRawBits() < rightHandSide.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=( Fixed const & rightHandSide) const
{
	if (this->getRawBits() >= rightHandSide.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=( Fixed const & rightHandSide) const
{
	if (this->getRawBits() <= rightHandSide.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator==( Fixed const & rightHandSide) const
{
	if (this->getRawBits() == rightHandSide.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=( Fixed const & rightHandSide) const
{
	if (this->getRawBits() != rightHandSide.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+( Fixed const & rightHandSide) const
{
	Fixed ret(this->toFloat() + rightHandSide.toFloat());
	
	return (ret);
}

Fixed Fixed::operator-( Fixed const & rightHandSide) const
{
	Fixed ret(this->toFloat() - rightHandSide.toFloat());
	
	return (ret);
}

Fixed Fixed::operator*( Fixed const & rightHandSide) const
{
	Fixed ret(this->toFloat() * rightHandSide.toFloat());

	return (ret);
}

Fixed Fixed::operator/( Fixed const & rightHandSide) const
{
	Fixed ret(this->toFloat() / rightHandSide.toFloat());
	
	return (ret);
}

Fixed & Fixed::operator++( void )
{
	this->_bit += 1;
	return (*this);
}

Fixed & Fixed::operator--( void )
{
	this->_bit -= 1;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed	temp = *this;

	(this->_bit) +=1 ;
	return (temp);
}

Fixed Fixed::operator--( int )
{
	Fixed	temp = *this;

	(this->_bit) -=1 ;
	return (temp);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}
	
const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}
	
Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}
