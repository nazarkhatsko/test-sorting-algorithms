#include "tools.hpp"
#include "algorithms.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>


auto main() -> int {

	std::cout << std::fixed;

	std::cout << "TSA (Test Sort Algorithm)" << '\n';
	std::cout << "Version 1.0" << '\n';
	std::cout << '\n';

	auto size = std::stol(input("enter size: "));
	auto min = std::stoi(input("enter min: "));
	auto max = std::stoi(input("enter max: "));
	auto vec = gen_rand_vec(size, min, max);

	auto start = std::chrono::steady_clock::now();
	std::vector<std::pair<std::string, double>> res = {
		{"bubble sort", test_algorithm(vec, bubble_sort)},
		{"selection sort", test_algorithm(vec, selection_sort)},
		{"insertion sort", test_algorithm(vec, insertion_sort)},
		{"counting sort", test_algorithm(vec, counting_sort)},
		{"shell sort", test_algorithm(vec, shell_sort)}
	};
	auto end = std::chrono::steady_clock::now();

	std::sort(res.begin(), res.end(), [](const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {
		return (a.second < b.second);
	});
	print_result(res);

	std::cout << "total time: " << std::chrono::duration<double>(end - start).count() << '\n';

	return (0);

};
