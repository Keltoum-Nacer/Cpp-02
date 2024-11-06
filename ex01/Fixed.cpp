/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:18:02 by knacer            #+#    #+#             */
/*   Updated: 2024/11/06 17:20:06 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed()
{
    fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    fixed_point = n << frac_bits;
    std::cout << "Int constructor called!" << std::endl;
}

Fixed::Fixed(const float number)
{
    fixed_point = static_cast<int>(roundf(number * (1 << frac_bits)));
    std::cout << "Float constructor called!" << std::endl;
}

Fixed::~Fixed()
{
    std::cout <<"Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &number)
{
    std::cout << "Copy constructor called" << std::endl;
    operator=(number);
}

Fixed& Fixed::operator=(const Fixed& number)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &number)
    {
        setRawBits(number.fixed_point);
        getRawBits();   
    }
    return( *this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

int Fixed::toInt( void ) const
{
    return(fixed_point >> frac_bits) ;
}

float Fixed::toFloat( void ) const
{
    return(fixed_point / (1 << frac_bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& number)
{
    out << number.toFloat();
    return(out);
}
