#include "tools.hpp"
#include "algorithms.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <functional>


auto gen_rand_vec(long int size, num_t a, num_t b) -> arr_t {

	std::vector<num_t> v(size);
	std::default_random_engine gen;
	std::uniform_int_distribution<num_t> db(a, b);
	for (auto &i : v) {
		i = db(gen);
	};
	return v;

};


auto main() -> int {

	std::cout << std::fixed;

	std::cout << "TSA (Test Sort Algorithm)" << '\n';
	std::cout << "Version 1.1 (CLI)" << '\n';
	std::cout << '\n';

	auto size = std::stol(input("enter size: "));
	auto min = std::stoi(input("enter min: "));
	auto max = std::stoi(input("enter max: "));
	auto vec = gen_rand_vec(size, min, max);
	auto comp = [](const num_t &a, const num_t &b) -> bool {
		return a < b;
	};

	auto start = std::chrono::steady_clock::now();
	auto res = std::vector<pair_t>({
		{"bubble sort", test_algorithm(std::bind(bubble_sort, vec, comp))},
		{"selection sort", test_algorithm(std::bind(selection_sort, vec, comp))},
		{"insertion sort", test_algorithm(std::bind(insertion_sort, vec, comp))},
		{"merge sort", test_algorithm(std::bind(merge_sort, vec, comp))},
		{"quick sort", test_algorithm(std::bind(quick_sort, vec, comp))},
		{"counting sort", test_algorithm(std::bind(counting_sort, vec, comp))},
		{"shell sort", test_algorithm(std::bind(shell_sort, vec, comp))}
	});
	auto end = std::chrono::steady_clock::now();

	std::sort(res.begin(), res.end(), [](const pair_t &a, const pair_t &b) -> bool {
		return a.second < b.second;
	});
	print_result(res);

	std::cout << "total time: " << std::chrono::duration<double>(end - start).count() << '\n';

	return 0;

};
