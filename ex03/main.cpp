/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knacer <knacer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:32:27 by knacer            #+#    #+#             */
/*   Updated: 2024/11/02 10:26:13 by knacer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);
    Point p(0.0f, 0.0f);

    if (bsp(a, b, c, p))
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is NOT inside the triangle." << std::endl;

    return 0;
}
