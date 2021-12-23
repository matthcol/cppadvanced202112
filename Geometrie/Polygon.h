#pragma once

#include <vector>
#include "Form.h"
#include "IMesurable2D.h"
#include "Point2D.h"

using namespace std;

class Polygon :
    public Form, IMesurable2D
{
private:
    vector <Point2D> m_summits;

public:
    Polygon(const string& name, initializer_list<Point2D> summits);
    virtual ~Polygon();

    int size() const;
    const Point2D& summit(int index) const;
    
    // surcharges operator []
    const Point2D& operator[](int index) const;
    Point2D& operator[](int index);
    
    // Hérité via IMesurable2D
    virtual double perimeter() const override;

    virtual double area() const override;


    // Hérité via Form
    virtual void translate(double deltaX, double deltaY) override;

};

