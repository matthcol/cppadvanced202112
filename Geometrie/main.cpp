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

	cout << ptA.x() << "," << ptA.y() << endl;

	// copy with constructor by copy (default)
	/*Point2D ptAbis(ptA);
	Point2D ptAter = Point2D(ptA);

	cout << "Abis : " << ptAbis << endl;
	cout << "Ater : " << ptAter << endl;*/

	// operator copy (default)
	// ptAter = ptB;
	ptB = ptA;
	// cout << "Ater modifié : " << ptAter << endl;
	cout << "Ater modifié : " << ptB << endl;

	// exemple de move
	Point2D ptD(std::move(Point2D("D", 3.5, 6.0)));

	Polygon tri2("T2", { ptA, ptB, Point2D("E",5.0, 6.6)});

	Point2D ptBmove(std::move(ptB));

	cout << "B after move: " << ptB << endl;
	cout << "B moved: " << ptBmove << endl;

	return EXIT_SUCCESS;
}







