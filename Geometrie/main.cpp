#include <cstdlib>
#include <iostream>
#include <memory>
#include <optional>

#include "Point2D.h"
#include "Form.h"
#include "Polygon.h"

int oop_demo()
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

	return 0;
}

//auto_ptr<Point2D> init_data() {
unique_ptr<Point2D> init_data() {
	// auto_ptr<Point2D> ptB_ptr(new Point2D("B", 3.0, 4.0));
	unique_ptr<Point2D> ptB_ptr(new Point2D("B", 3.0, 4.0));
	return ptB_ptr;
}

int smart_pointer_demo_auto() {
	cout << "Begin Demo" << endl;
	// auto_ptr<Point2D> ptB_ptr(init_data()); // C++14
	unique_ptr<Point2D> ptB_ptr(init_data()); // C++14
	Point2D ptA("A", 1.0, 2.0);

	cout << *ptB_ptr << endl;
	ptB_ptr->translate(1, -1);
	cout << ptB_ptr->name() << endl;

	Point2D* ptr_oldschool = ptB_ptr.get();

	// ptB_ptr.release(); // relache la donnee si besoin
	cout << "End Demo" << endl;
	return 0;
} // delete data derriere l'auto_ptr


shared_ptr<Point2D> init_data_shared() 
{
	shared_ptr<Point2D> res(new Point2D("A", 3.0, 4.0));
	cout << "Init: " << *res << " : " << res.use_count() << endl;
	return res;
}

void use_data_shared(shared_ptr<Point2D> point_ptr)
{
	point_ptr->translate(1.0, -1.0);
	cout << "Use: " << *point_ptr << " : " << point_ptr.use_count() << endl;
}

int smart_pointer_demo_shared()
{
	shared_ptr<Point2D> point_ptr(init_data_shared());
	cout << "Demo (after init): " << *point_ptr << " : " << point_ptr.use_count() << endl;
	use_data_shared(point_ptr);
	cout << "Demo (after use): " << *point_ptr << " : " << point_ptr.use_count() << endl;
	return 0;
} // shared_ptr delete Point2D

int demo_reference_wrapper() 
{
	// Point2D*& t; // ok dans l'absolu
	// Point2D&* t; // nok
	// vector<Point2D&> points; // nok car * sur &
	Point2D ptA("A", 10.0, 10.0);
	Point2D ptB("B", 3.0, 4.0);
	Point2D ptC("C", 3.0, 4.0);
	vector<reference_wrapper<Point2D>> points{ ptA, ptB };
	points.push_back(std::ref(ptC));
	ptA.translate(1, -1);
	for (auto pt : points)
	{
		cout << "In vector:" << pt << endl;
	}
	return 0;
}

optional<string> getNameFromForm(const Form& form)
{
	return form.name().empty() ? optional<string>() : optional<string>(form.name());
}

void dealWithOptional(const optional<string>& nameOpt) 
{
	if (nameOpt.has_value())
	{
		cout << "Name here: " << nameOpt.value() << " / " << *nameOpt << endl;
		cout << "Size: " << nameOpt->size() << endl;
	}
}

// https://en.cppreference.com/w/cpp/utility/optional
void demoOptional() {
	Point2D ptO; // name = ""
	Point2D ptA("A", 3.0, 4.0);
	dealWithOptional(getNameFromForm(ptO));
	dealWithOptional(getNameFromForm(ptA));
}

void demoCastReference() {
	Point2D ptA("A", 3.0, 4.0);
	Polygon tri ("T", { ptA, Point2D("B", 1.0, 4.1), Point2D("C", 1.0, 2.0) });
	vector<reference_wrapper<Form>> forms{ ptA, tri };
	for (auto f : forms) 
	{
		cout << f.get().name() << endl;
		// if f est mesurable afficher area et perimeter
		try 
		{
			IMesurable2D& m = dynamic_cast<IMesurable2D&>(f.get());
			cout << "Area: " << m.area() << " / Perimeter: " << m.perimeter() << endl;
		}
		catch (bad_cast& e) 
		{
			cout << "No mesure" << endl;
		}
	}
}

void demoCastPointer() {
	Point2D ptA("A", 3.0, 4.0);
	Polygon tri("T", { ptA, Point2D("B", 1.0, 4.1), Point2D("C", 1.0, 2.0) });
	vector<Form*> forms{ &ptA, &tri };
	for (auto f : forms) {
		cout << f->name() << endl;
		// if f est mesurable afficher area et perimeter
		// if (Polygon* m = dynamic_cast<Polygon*>(f))
		if (IMesurable2D* m = dynamic_cast<IMesurable2D*>(f))
		{
			cout << "Area: " << m->area() << " / Perimeter: " << m->perimeter() << endl;
		}
		if (typeid(*f) == typeid(Point2D)) 
		{
			cout << "This is a point: " << typeid(*f).name() << endl;
		}
	}
}

class A {
public:
	A(int n) {}
};

class B {
public:
	explicit B(int n) {}
};

void f(A a, B b) {}

void demoImplicitExplicit()
{
	A a(3);
	a = 5;
	B b(3);
	// b = 5;  // NOK: 5 can't be implicitly converted in B
	f(3, b);
	// f(5, 7); // NOK: 7 can't be implicitly converted in B
}

int main() {
	// oop_demo();
	// smart_pointer_demo_auto();
	// smart_pointer_demo_shared();
	//demo_reference_wrapper();
	//cout << "Main: after demo" << endl;
	// demoOptional();
	demoCastReference();
	demoCastPointer();
	return EXIT_SUCCESS;
}







