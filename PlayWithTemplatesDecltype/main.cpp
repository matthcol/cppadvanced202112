// SFINAE : Substitution Failure is not an Error
// https://en.cppreference.com/w/cpp/language/sfinae
// choix de surcharge entre fonction ou entre classes

#include <iostream>

int f(double x, const char* s) 
{
	return 0;
}

template <class T, class U>
auto f(T t, U u) -> decltype(t + u)
{
	return t + u;
}

template <class T, class U>
auto f(T t, U u) -> decltype(u[0], u)
{
	return u;
}

void test_f_ou_f() {
	auto res1 = f(12.0, "aaa");
	auto res2 = f(12.3, 5);
	auto res3 = f(12, 5.6);
	auto res4 = f("sylvain", "nicolas");
}


class A 
{
public:
	int duckme() {
		std::cout << "Duck duck ! " << std::endl;
		return 3;
	}
};

class B
{
public:
	double fickme() {
		std::cout << "Fick you ! " << std::endl;
		return 3.14;
	}
};

class C
{
public:
	long long duckme() {
		std::cout << "Duck you ! " << std::endl;
		return 100000000000000LL;
	}
};

template<class T>
auto playWithT(T t) -> decltype(t.duckme(), void())
{
	std::cout << t.duckme() << std::endl;
}

template<class T>
auto playWithT(T t) -> decltype(t.fickme(), void())
{
	std::cout << t.fickme() << std::endl;
}

void test_play_with_t() {
	A a;
	B b;
	C c;
	playWithT(a);
	playWithT(b);
	playWithT(c);
}

int main() 
{
	test_play_with_t();
	return EXIT_SUCCESS;
}
