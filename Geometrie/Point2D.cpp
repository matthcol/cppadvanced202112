#include "Point2D.h"

#include <iostream>

//Point2D::Point2D():Point2D("", 0.0, 0.0)
//{
//}

Point2D::Point2D(const string& name, double x, double y):
    Form(name), m_x(x), m_y(y)
{
}

Point2D::Point2D(Point2D&& pt) noexcept:
    Form(pt),m_x(pt.m_x), m_y(pt.m_y)
{
    std::clog << "Move Pt2D: " << pt.name() << std::endl;
    pt.setX(0);
    pt.setY(0);
}

Point2D::~Point2D()
{
        std::clog << *this << " destroyed" << std::endl;
}

constexpr double Point2D::x() const
{
    return m_x;
}

constexpr void Point2D::setX(double x)
{
    m_x = x;
}

double Point2D::y() const
{
    return m_y;
}

void Point2D::setY(double y)
{
    m_y = y;
}

void Point2D::translate(double deltaX, double deltaY)
{
    m_x += deltaX;
    m_y += deltaY;
}

ostream& operator<<(ostream& out, const Point2D& pt)
{
    return out << pt.name() << "(" << pt.x() << "," << pt.y() << ")";
}
