#include <cstdlib>
#include <iostream>

#include "Point2D.h"
#include "Form.h"
#include "Polygon.h"

int main()
{
	Point2D ptA("A", 3.0, 4.5);
	Form& f = ptA;
	Form* ptr_f = &ptA;

	Point2D ptO;
	Point2D ptB("B", 3.3, 6.6);

	Polygon triangle("T1", { ptA, ptB, ptO });

	f.translate(1.0, -1);
	ptr_f->translate(2.0, -2.0);

	cout << ptA.x() << "," << ptA.y();
	return EXIT_SUCCESS;
}