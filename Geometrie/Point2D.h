#pragma once
#include <ostream>

#include "Form.h"

class Point2D :
    public Form
{
private:
    double m_x;
    double m_y;
public:
    Point2D() = default;
    Point2D(const string& name, double x, double y);

    // copy constructor
    // Point2D(const Point2D& pt) = delete;
    Point2D(const Point2D& pt) = default;

    //move constructor
    Point2D(Point2D&& pt) noexcept; 

    virtual ~Point2D();

    // Point2D& operator=(const Point2D& pt) = delete;
    Point2D& operator=(const Point2D& pt) = default;

    constexpr double x() const;
    constexpr void setX(double x);

    double y() const;
    void setY(double y);

    virtual void translate(double deltaX, double deltaY) override;
};

ostream& operator<<(ostream& out, const Point2D& pt);