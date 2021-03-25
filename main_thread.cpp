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


auto gen_rand_vec(long int size, num_t a, num_t b) -> arr_t {

	std::vector<num_t> v(size);
	std::default_random_engine gen;
	std::uniform_int_distribution<num_t> db(a, b);
	for (auto &i : v) {
		i = db(gen);
	};
	return v;

};


auto wrapper_for_thread(std::function<double()> f, double &r) -> void {

	r = f();

};


auto main() -> int {

	std::cout << std::fixed;

	std::cout << "TSA (Test Sort Algorithm)" << '\n';
	std::cout << "Version 1.1 (thread)" << '\n';
	std::cout << '\n';

	auto size = std::stol(input("enter size: "));
	auto min = std::stoi(input("enter min: "));
	auto max = std::stoi(input("enter max: "));
	auto vec = gen_rand_vec(size, min, max);
	auto comp = [](const num_t &a, const num_t &b) -> bool {
		return a < b;
	};

	auto res = std::vector<pair_t>({
		{"bubble sort", 0.0},
		{"selection sort", 0.0},
		{"insertion sort", 0.0},
		{"merge sort", 0.0},
		{"quick sort", 0.0},
		{"counting sort", 0.0},
		{"shell sort", 0.0}
	});

	auto start = std::chrono::steady_clock::now();

	auto ths = std::vector<std::thread>(7);

	ths.at(0) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		arr_t v(vec);
		bubble_sort(v, comp);
	}), std::ref(res.at(0).second));

	ths.at(1) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		arr_t v(vec);
		selection_sort(v, comp);
	}), std::ref(res.at(1).second));

	ths.at(2) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		arr_t v(vec);
		insertion_sort(v, comp);
	}), std::ref(res.at(2).second));

	ths.at(3) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		arr_t v(vec);
		merge_sort(v, comp);
	}), std::ref(res.at(3).second));

	ths.at(4) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		arr_t v(vec);
		quick_sort(v, comp);
	}), std::ref(res.at(4).second));

	ths.at(5) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		arr_t v(vec);
		counting_sort(v, comp);
	}), std::ref(res.at(5).second));

	ths.at(6) = std::thread(wrapper_for_thread, std::bind(test_algorithm, [&]() {
		arr_t v(vec);
		shell_sort(v, comp);
	}), std::ref(res.at(6).second));

	for (auto &i : ths) {
		if (i.joinable()) {
			i.join();
		};
	};

	auto end = std::chrono::steady_clock::now();

	std::sort(res.begin(), res.end(), [](const pair_t &a, const pair_t &b) -> bool {
		return a.second < b.second;
	});
	print_result(res);

	std::cout << "total time: " << std::chrono::duration<double>(end - start).count() << '\n';

	return 0;

};
