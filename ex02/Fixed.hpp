/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:25:18 by krochefo          #+#    #+#             */
/*   Updated: 2023/04/12 00:22:01 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

# include <iostream>
# include <cmath>

class Fixed{
private:
	int _bit;
	static const int _rawBit = 8;
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed( Fixed const & copy );
	Fixed &operator=(Fixed const & copy);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	int operator>( Fixed const & rightHandSide) const;
	int operator<( Fixed const & rightHandSide) const;
	int operator>=( Fixed const & rightHandSide) const;
	int operator<=( Fixed const & rightHandSide) const;
	int operator==( Fixed const & rightHandSide) const;
	int operator!=( Fixed const & rightHandSide) const;
	Fixed operator+( Fixed const & rightHandSide) const;
	Fixed operator-( Fixed const & rightHandSide) const;
	Fixed operator*( Fixed const & rightHandSide) const;
	Fixed operator/( Fixed const & rightHandSide) const;
	Fixed & operator++( void );
	Fixed & operator--( void );
	Fixed operator++( int n );
	Fixed operator--( int n );
	static Fixed & min(Fixed & a, Fixed & b );
	static Fixed & max(Fixed & a, Fixed & b );
	static const Fixed & min(const Fixed & a, const Fixed & b );
	static const Fixed & max(const Fixed & a, const Fixed & b );

};

std::ostream &operator<<(std::ostream &out, const Fixed &rightHandSide);

#endif