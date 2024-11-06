/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:05:54 by knacer            #+#    #+#             */
/*   Updated: 2024/11/02 09:36:35 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include<iostream>

class Fixed
{
    private:
        int fixed_point;
        static const int frac_bits;
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed& number);
        Fixed& operator=(Fixed& number);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif
