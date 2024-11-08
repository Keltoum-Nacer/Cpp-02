#ifndef POINT_HPP
#define POINT_HPP

#include"Fixed.hpp"

class Point 
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float a, const float b);
        Point(const Point& copy);
        Point& operator=(const Point& copy); 
        ~Point();
        const Fixed& getX() const;
        const Fixed& getY() const;
};

#endif
