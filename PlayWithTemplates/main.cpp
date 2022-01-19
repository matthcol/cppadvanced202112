#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

template<class T>
class Data
{
private:
	T m_t;
public:
	const T& get() const { return m_t;  }
	void set(const T& t) { m_t = t; }
	void set(T&& t) { m_t = forward<T>(t); }
};

template<>
class Data<int>
{
private:
	int m_t;
public:
	int get() const { return m_t; }
	void set(int t) { m_t = t; }

	static int neutralValue() 
	{
		return 0;
	}
};

template<class T>
void useData(const Data<T>& data) {
	cout << "Using generic Data<T> : " << data.get() << endl;
}

void demoData() {
	Data<int> data_int;
	Data<string> data_string;
	Data<vector<list<int>>> data_complex;
	
	data_int.set(5);
	data_string.set("Toulouse");

	cout << "Data<int> : " << data_int.get() << endl;
	
	cout << "Neutral value Data<int>: " << Data<int>::neutralValue() << endl;
	// cout << "Neutral value Data<string>: " << Data<string>::neutralValue() << endl;
	// No Compil :
	// cout << "Neutral value Data<complex>: " << Data<vector<list<int>>>::neutralValue() << endl;

	useData(data_int);
	useData(data_string);
	// useData(data_complex);  // operator<< not defined for T=vector<list<....
}

int main() 
{
	demoData();
	return EXIT_SUCCESS;
}