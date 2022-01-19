#include <iostream>
#include <iomanip>
#include <numbers>
#include <format>
#include <ranges>

void test_numeric_constants()
{
	std::cout << "PI = " << std::setprecision(15) << std::numbers::pi << std::endl;
	std::cout << "PI = " << std::numbers::pi_v<float> << std::endl;
}

// https://en.cppreference.com/w/cpp/utility/compare/three_way_comparable
void test_spaceship_operator() 
{
	std::string city1 = "Toulouse";
	std::string city2 = "Pau";
	auto res = city1 <=> city2;
	// std::is_lteq
	// std::is_lt
	// std::is_gteq
	if (std::is_gt(res)) {
		std::cout << city1 << " > " << city2;
	}

}

//void test_ranges() {
//	auto const ints = { 0,1,2,3,4,5 };
//	auto even = [](int i) { return 0 == i % 2; };
//	auto square = [](int i) { return i * i; };
//
//	// "pipe" syntax of composing the views:
//	for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
//		std::cout << i << ' ';
//	}
//}

//void test_frmatting() {
//	std::string message = std::format("The answer is {}.", 42);
//}

int main() 
{
	// test_numeric_constants();
	test_spaceship_operator();
	return EXIT_SUCCESS;
}