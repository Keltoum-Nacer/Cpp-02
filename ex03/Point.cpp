#include"Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0))
{
    std::cout << "Point Default constructor called" << std::endl;
}

Point::Point(const float a, const float b): x(Fixed(a)), y(Fixed(b))
{
    std::cout << "Point constructor called" << std::endl;
}

Point::Point(const Point& copy) : x(copy.x), y(copy.y)
{
    std::cout << "Point Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& copy)
{
    std::cout << "Point copy Assignement operator called" << std::endl;
    if (this != &copy)
    {
        return(*this);
    }
    return(*this);
}

Point::~Point()
{
    std::cout << "Point destructor called" << std::endl;
}

const Fixed& Point::getX() const
{
    return(x);
}

const Fixed& Point::getY() const
{
    return(y);
}
