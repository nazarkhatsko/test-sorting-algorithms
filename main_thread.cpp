#include "tools.hpp"
#include "algorithms.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <algorithm>
#include <functional>


auto wrapper_for_thread(std::function<double()> f, double &r) -> void {

	r = f();

};


auto main() -> int {

	std::cout << std::fixed;

	std::cout << "TSA (Test Sort Algorithm)" << '\n';
	std::cout << "Version 1.0 (thread)" << '\n';
	std::cout << '\n';

	auto size = std::stol(input("enter size: "));
	auto min = std::stoi(input("enter min: "));
	auto max = std::stoi(input("enter max: "));
	auto vec = gen_rand_vec(size, min, max);

	std::vector<std::pair<std::string, double>> res = {
		{"bubble sort", 0.0},
		{"selection sort", 0.0},
		{"insertion sort", 0.0},
		{"counting sort", 0.0},
		{"shell sort", 0.0}
	};

	auto start = std::chrono::steady_clock::now();

	std::vector<std::function<void(std::vector<int> &)>> funcs = {
		bubble_sort, selection_sort, insertion_sort,
		counting_sort, shell_sort
	};

	std::vector<std::thread> ths;
	for (int i = 0; i < res.size(); i++) {
		ths.push_back(std::thread(
			wrapper_for_thread,
			std::bind(test_algorithm, vec, funcs[i]),
			std::ref(res[i].second)
		));
	};

	for (auto &i : ths) {
		if (i.joinable()) {
			i.join();
		};
	};

	auto end = std::chrono::steady_clock::now();

	std::sort(res.begin(), res.end(), [](const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {
		return (a.second < b.second);
	});
	print_result(res);

	std::cout << "total time: " << std::chrono::duration<double>(end - start).count() << '\n';

	return (0);

};
