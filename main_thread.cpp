#include "tools.hpp"
#include "algorithms.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <random>
#include <algorithm>
#include <functional>


std::vector<data_t> generate_array(std::size_t size, data_t a, data_t b) {

	std::vector<data_t> v(size);
	std::default_random_engine gen;
	std::uniform_int_distribution<data_t> db(a, b);
	for (auto &i : v) {
		i = db(gen);
	};
	return v;

};


void wrapper_for_thread(std::function<double()> f, double &r) {

	r = f();

};


void wrapper_for_sort(std::function<void()> f) {

	f();

};


int main() {

	std::cout << std::fixed;

	std::cout << "TSA (Test Sorting Algorithms)" << '\n';
	std::cout << "Version 1.1" << '\n';
	std::cout << '\n';

	auto size = std::stoi(input("enter size: "));
	auto min = std::stoi(input("enter min: "));
	auto max = std::stoi(input("enter max: "));
	auto array = generate_array(size, min, max);
	auto comparison = [](const data_t &a, const data_t &b) {
		return a < b;
	};

	auto result = std::vector<pair_t>({
		{"bubble sort", 0.0},
		{"selection sort", 0.0},
		{"insertion sort", 0.0},
		{"merge sort", 0.0},
		{"quick sort", 0.0},
		{"shell sort", 0.0}
	});

	auto start = std::chrono::steady_clock::now();

	auto threads = std::vector<std::thread>(6);

	threads.at(0) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		wrapper_for_sort(std::bind(bubble_sort, array, comparison));
	}), std::ref(result.at(0).second));

	threads.at(1) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		wrapper_for_sort(std::bind(selection_sort, array, comparison));
	}), std::ref(result.at(1).second));

	threads.at(2) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		wrapper_for_sort(std::bind(insertion_sort, array, comparison));
	}), std::ref(result.at(2).second));

	threads.at(3) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		wrapper_for_sort(std::bind(merge_sort, array, comparison));
	}), std::ref(result.at(3).second));

	threads.at(4) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		wrapper_for_sort(std::bind(quick_sort, array, comparison));
	}), std::ref(result.at(4).second));

	threads.at(5) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		wrapper_for_sort(std::bind(shell_sort, array, comparison));
	}), std::ref(result.at(5).second));

	for (auto &i : threads) {
		if (i.joinable()) {
			i.join();
		};
	};

	auto end = std::chrono::steady_clock::now();

	std::sort(result.begin(), result.end(), [](const pair_t &a, const pair_t &b) {
		return a.second < b.second;
	});
	print_result(result);

	std::cout << "total time: " << std::chrono::duration<double>(end - start).count() << '\n';

	return 0;

};
