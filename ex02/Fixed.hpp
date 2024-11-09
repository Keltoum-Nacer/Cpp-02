/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:05:54 by knacer            #+#    #+#             */
/*   Updated: 2024/11/09 14:10:51 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include<iostream>
#include<cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int frac_bits;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int n);
        Fixed(const float number);
        Fixed(const Fixed& number);
        Fixed& operator=(const Fixed& number);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed operator>(const Fixed& num);
        Fixed operator>=(const Fixed& num);
        Fixed operator<(const Fixed& num);
        Fixed operator<=(const Fixed& num);
        Fixed operator==(const Fixed& num);
        Fixed operator!=(const Fixed& num);
        Fixed operator+(const Fixed& num);
        Fixed operator-(const Fixed& num);
        Fixed operator*(const Fixed& num);
        Fixed operator/(const Fixed& num);
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        static Fixed& min(Fixed& num1, Fixed& num2);
        static const Fixed& min(const Fixed& num1, const Fixed& num2);
        static Fixed& max(Fixed& num1, Fixed& num2);
        static const Fixed& max(const Fixed& num1, const Fixed& num2);
};
    std::ostream& operator<<(std::ostream& out, const Fixed& number);

#endif
