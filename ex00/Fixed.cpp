/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:18:02 by knacer            #+#    #+#             */
/*   Updated: 2024/11/05 13:19:52 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed()
{
    fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout <<"Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &number)
{
    std::cout << "Copy constructor called" << std::endl;
    operator=(number);
}

Fixed& Fixed::operator=(Fixed& number)
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
