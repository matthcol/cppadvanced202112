#include <iostream>

#include "heron.h"

int main()
{
	double area = aire_triangle_heron(3.0, 4.0, 5.0);
	std::cout << "Aire: " << area << std::endl;
	return EXIT_SUCCESS;
}