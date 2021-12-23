#pragma once
class IMesurable2D
{
public:
	virtual ~IMesurable2D(){}

	virtual double perimeter() const = 0;
	virtual double area() const = 0;
};

