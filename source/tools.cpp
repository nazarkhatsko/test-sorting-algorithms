#include "tools.hpp"


std::string input(const std::string &s) {

	std::cout << s;
	std::string r;
	std::cin >> r;
	return r;

};


void print_result(const std::vector<pair_t> &v) {

	std::cout << '\n';
	std::cout << "COUNT\tNAME\t\tTIME\n";
	size_t count = 1;
	for (auto i : v) {
		std::cout << count++ << '\t' << i.first << '\t' << i.second << '\n';
	};
	std::cout << '\n';

};


double test_algorithm(std::function<void()> f) {

	auto start = std::chrono::steady_clock::now();
	f();
	auto end = std::chrono::steady_clock::now();
	return std::chrono::duration<double>(end - start).count();

};
