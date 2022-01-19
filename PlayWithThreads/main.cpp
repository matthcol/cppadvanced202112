#include <iostream>
#include <cstdint>
#include <thread>
#include <future>

double compute(double x) {
	double res = x;
	for (uint64_t i = 0; i < 500000000; i++ )
	{
		res = (res + 1) * 2;
 	}
	return res;
}

// resultat dans variable en sortie
void compute_out(double x, double& res) {
	res = x;
	for (uint64_t i = 0; i < 500000000; i++)
	{
		res = (res + 1) * 2;
	}
}


void test_compute() 
{
	double res = compute(5.0);
	std::cout << "Call synchronous: " << res << std::endl;
}

void test_compute_async() 
{
	double res=5;
	std::thread t1([&res]() {compute_out(5, res);});
	std::cout << "Do something while computing...." << std::endl;
	t1.join();
	std::cout << "Resultat (after join) : " << res << std::endl;
}

// see also std::async et std::promise
void test_compute_async_future()
{
	double x = 5;
	std::packaged_task<double(double)> task1(compute);
	std::future<double> res_future = task1.get_future();
	// affecter la tache à un thread
	std::thread t(std::move(task1), x);
	std::cout << "Do something while computing...." << std::endl;
	
	// wait and get the result
	double res = res_future.get();
	std::cout << "Res async future: " << res << std::endl;

	// TODO: affecter une autre tache
	//std::packaged_task<double()> task2([]() {compute(3);});
	//t = std::move(task2);

	t.join();
}

int main() 
{
	// std::cout << "long : " << sizeof(long) << std::endl;
	// std::cout << "long long : " << sizeof(long long) << std::endl;
	test_compute_async_future();
	return EXIT_SUCCESS;
}