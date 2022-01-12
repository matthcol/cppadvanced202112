#include "Polygon.h"

Polygon::Polygon(const string& name, initializer_list<Point2D> summits):
    Form(name), m_summits(summits.begin(), summits.end())
{

}

Polygon::~Polygon()
{
}

int Polygon::size() const
{
    return 0;
}

const Point2D& Polygon::summit(int index) const
{
    return m_summits[index];
}

const Point2D& Polygon::operator[](int index) const
{
    return m_summits[index];
}

Point2D& Polygon::operator[](int index)
{
    return m_summits[index];
}

double Polygon::perimeter() const
{
    // TODO
    return 0.0;
}

double Polygon::area() const
{
    // TODO
    return 0.0;
}

void Polygon::translate(double deltaX, double deltaY)
{
}
