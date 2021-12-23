#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <list>
#include <map>
#include <iterator>

#include "tools.h"
#include "main.h"
using namespace std;


void panorama() 
{
	// random access : O(1)
	vector<double> v_temperatures{12.3, 4.5, 5.67, 25.3, -12.3, 45.7};
	// aka vector<double> v_temperatures = vector<double>{ 12.3, 4.5, 5.67, 25.3 };
	vector<string> days{ "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
	
	array<double, 100> a_temperatures;

	// ensemble ordonnée : acces/ajout log(n)
	set<double> s_temperatures(v_temperatures.begin(), v_temperatures.end());
	
	// liste doublement chainee : acces n
	// OK : insertion/suppression
	list<double> l_temperatures(s_temperatures.rbegin(), s_temperatures.rend());

	// indexation
	map<string, double> m_tempByday{ {"monday",12.5}, {"tuesday",20.5} };

	for (auto temp: v_temperatures) 
	{
		cout << temp << endl;
	}

	// for (auto day : days) {
	for (auto& day : days) {
	// for (const auto& day : days) {
		day += "_";
		cout << day << endl;
	}

	// for (list<double>::iterator it = l_temperatures.begin(); it != l_temperatures.end(); ++it) {
	for (auto it = l_temperatures.begin(); it != l_temperatures.end(); ++it) {
		// auto temp = *it;
		double temp = *it;
		cout << temp << endl;
	}

	auto it_temp = l_temperatures.begin();
	auto end_temp = l_temperatures.end();
	advance(it_temp,2); // += 2;
	advance(end_temp, -2); // -= 2;
	while (it_temp != end_temp) {
		cout << "partiel: " << *it_temp << endl;
		++it_temp;
	}

	displayIterable(v_temperatures.cbegin(), v_temperatures.cend());
	displayIterable(v_temperatures.cbegin()+2, v_temperatures.cend()-2);
	displayIterable(
		next(l_temperatures.cbegin(), 2), 
		prev(l_temperatures.cend(), 2));
	displayIterable(
		l_temperatures.cbegin(),
		next(l_temperatures.cbegin(), 4));
	displayContainer(v_temperatures);
	cout << endl << endl;
	displayContainer(a_temperatures);
}

int main() 
{
	panorama();
	return EXIT_SUCCESS;
}