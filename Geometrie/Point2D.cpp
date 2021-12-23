#include "Point2D.h"

Point2D::Point2D():Point2D("", 0.0, 0.0)
{
}

Point2D::Point2D(const string& name, double x, double y):Form(name), m_x(x), m_y(y)
{
}

Point2D::~Point2D()
{
}

double Point2D::x() const
{
    return m_x;
}

void Point2D::setX(double x)
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
