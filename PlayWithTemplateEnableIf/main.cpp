#include <iostream>

// https://en.cppreference.com/w/cpp/types/enable_if

class A
{
public:
	A() = delete;
	A(int x){}
};

template<class T>
typename std::enable_if<std::is_integral<T>::value, T>::type
makeT()
{
	std::cout << "Make integral type" << std::endl;
	return (T)0;
}

template <class T>
typename std::enable_if<!std::is_integral<T>::value && std::is_default_constructible<T>::value, T>::type
makeT() 
{
	std::cout << "Make not integral but default constructible type" << std::endl;
	T t;
	return t;
}

template <class T>
typename std::enable_if<
	!std::is_default_constructible<T>::value
	&& std::is_constructible<T,int>::value,	
	T>::type
makeT()
{
	std::cout << "Make not default constructible type" << std::endl;
	T t(3);
	return t;
}

void test_makeT() {
	auto res1 = makeT<std::string>();
	auto res2 = makeT<int>();
	auto res3 = makeT<A>();
}


int main() {
	test_makeT();
	return EXIT_SUCCESS;
}