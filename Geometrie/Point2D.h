#pragma once
#include "Form.h"
class Point2D :
    public Form
{
private:
    double m_x;
    double m_y;
public:
    Point2D();
    Point2D(const string& name, double x, double y);
    virtual ~Point2D();

    double x() const;
    void setX(double x);

    double y() const;
    void setY(double y);

    virtual void translate(double deltaX, double deltaY) override;
};

