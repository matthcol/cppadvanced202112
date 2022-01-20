#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <condition_variable>

using namespace std::chrono_literals;

std::condition_variable cv_empty_buffer;
std::condition_variable cv_full_buffer;
std::mutex m;
uint32_t capacity = 0;

void produce(double* buffer, uint32_t taille, uint32_t times, int deltaStartMs, int deltaLoopMs)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(deltaStartMs));
	for (uint32_t i = 0; i < times; i++) {
		double data = i;

		{
			std::unique_lock<std::mutex> lk(m);
			cv_full_buffer.wait(lk, [taille] {return capacity != taille;});

			buffer[i % taille] = data;
			capacity ++;
			std::cout << "Produce: " << data << std::endl;
		}
		cv_empty_buffer.notify_one();

		
		// attente entre 2 productions
		std::this_thread::sleep_for(std::chrono::milliseconds(deltaLoopMs));
	}
}

void consume(double* buffer, uint32_t taille, uint32_t times, int deltaStartMs, int deltaLoopMs)
{
	// attente au start
	std::this_thread::sleep_for(std::chrono::milliseconds(deltaStartMs));

	// consomme dans le buffer times fois
	for (uint32_t i = 0; i < times; i++) {
		double data;
		{
			std::unique_lock<std::mutex> lk(m);
			cv_empty_buffer.wait(lk, [] {return capacity != 0;});
			data = buffer[i % taille];
			buffer[i % taille] = NAN;
			capacity--;
			std::cout << "\tConsume: " << data << std::endl;
		}
		cv_full_buffer.notify_one();
		
		// attente entre 2 consommations
		std::this_thread::sleep_for(std::chrono::milliseconds(deltaLoopMs));
	}
}

void run(double* buffer, uint32_t taille)
{
	std::thread threadProduce([=] {produce(buffer, taille, 30, 500, 10);});
	std::thread threadConsume([=] {consume(buffer, taille, 30, 0, 100);});
	threadProduce.join();
	threadConsume.join();
}

int main() 
{
	uint32_t taille = 10;
	double* buffer = new double[taille];
	std::fill(buffer, buffer+taille, NAN);
	run(buffer, taille);
	delete[] buffer;
	return EXIT_SUCCESS;
}