#include "tools.hpp"
#include "algorithms.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
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

	auto start = std::chrono::steady_clock::now();
	auto result = std::vector<pair_t>({
		{"bubble sort", test_algorithm(std::bind(bubble_sort, array, comparison))},
		{"selection sort", test_algorithm(std::bind(selection_sort, array, comparison))},
		{"insertion sort", test_algorithm(std::bind(insertion_sort, array, comparison))},
		{"merge sort", test_algorithm(std::bind(merge_sort, array, comparison))},
		{"quick sort", test_algorithm(std::bind(quick_sort, array, comparison))},
		{"shell sort", test_algorithm(std::bind(shell_sort, array, comparison))}
	});
	auto end = std::chrono::steady_clock::now();

	std::sort(result.begin(), result.end(), [](const pair_t &a, const pair_t &b) {
		return a.second < b.second;
	});
	print_result(result);

	std::cout << "total time: " << std::chrono::duration<double>(end - start).count() << '\n';

	return 0;

};
