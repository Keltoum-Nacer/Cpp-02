#include"Point.hpp"

float triangle_area(Point a, Point b, Point c)
{
    return(std::abs(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + b.getX().toFloat() *(c.getY().toFloat() - a.getY().toFloat()) + c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) * (1 / 2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float abc = triangle_area(a, b, c);
    float pab = triangle_area(point, a, b);
    float pbc = triangle_area(point, b, c);
    float pac = triangle_area(point, a, c);
    if (point.getX().toFloat() == a.getX().toFloat()  || point.getX().toFloat()  == b.getX().toFloat()  ||
         point.getX().toFloat()  == c.getX().toFloat()  || point.getY().toFloat()  == a.getY().toFloat()  || 
         point.getY().toFloat()  == b.getY().toFloat()  || point.getY().toFloat()  == c.getY().toFloat() )
        return(false);
    return(abc = pab + pbc + pac);
}