/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:18:02 by knacer            #+#    #+#             */
/*   Updated: 2024/11/07 13:52:08 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed()
{
    fixed_point = 0;
}

Fixed::Fixed(const int n)
{
    fixed_point = n << frac_bits;
}

Fixed::Fixed(const float number)
{
    fixed_point = static_cast<int>(roundf(number * (1 << frac_bits)));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &number)
{
    operator=(number);
}

Fixed& Fixed::operator=(const Fixed& number)
{
    if (this != &number)
    {
        setRawBits(number.fixed_point);
        getRawBits();   
    }
    return( *this);
}

int Fixed::getRawBits( void ) const
{
    return(fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

int Fixed::toInt( void ) const
{
    return(fixed_point >> 8) ;
}

float Fixed::toFloat( void ) const
{
    return((float)fixed_point / (1 << frac_bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& number)
{
    out << number.toFloat();
    return(out);
}

Fixed Fixed::operator>(const Fixed& num)
{
    return(Fixed(this->toFloat() > num.toFloat()));    
}

Fixed Fixed::operator>=(const Fixed& num)
{
    return(Fixed(this->toFloat() >= num.toFloat()));    
}

Fixed Fixed::operator<(const Fixed& num)
{
    return(Fixed(this->toFloat() < num.toFloat()));    
}

Fixed Fixed::operator<=(const Fixed& num)
{
    return(Fixed(this->toFloat() <= num.toFloat()));    
}

Fixed Fixed::operator==(const Fixed& num)
{
    return(Fixed(this->toFloat() == num.toFloat()));    
}

Fixed Fixed::operator!=(const Fixed& num)
{
    return(Fixed(this->toFloat() != num.toFloat()));    
}

Fixed Fixed::operator+(const Fixed& num)
{
    return(Fixed(this->toFloat() + num.toFloat()));    
}

Fixed Fixed::operator-(const Fixed& num)
{
    return(Fixed(this->toFloat() - num.toFloat()));    
}

Fixed Fixed::operator*(const Fixed& num)
{
    return(Fixed(this->toFloat() * num.toFloat()));    
}

Fixed Fixed::operator/(const Fixed& num)
{
    return(Fixed(this->toFloat() / num.toFloat()));    
}

Fixed& Fixed::operator++()
{
    this->fixed_point++;
    return(*this);
}

Fixed& Fixed::operator--()
{
    this->fixed_point--;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed nb;
    nb = *this;
    this->fixed_point++;
    return(nb);
}

Fixed Fixed::operator--(int)
{
    Fixed nb;
    nb = *this;
    this->fixed_point--;
    return(nb);
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
    if (num1.fixed_point > num2.fixed_point)
        return(num2);
    return(num1);
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
    if (num1.fixed_point > num2.fixed_point)
        return(num2);
    return(num1);
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
    if (num1.fixed_point > num2.fixed_point)
        return(num1);
    return(num2);
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
    if (num1.fixed_point > num2.fixed_point)
        return(num1);
    return(num2);
}