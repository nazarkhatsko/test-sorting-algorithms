#include "tools.hpp"


auto input(const std::string &s) -> std::string {

	std::cout << s;
	std::string r;
	std::cin >> r;
	return r;

};


auto print_result(const std::vector<pair_t> &v) -> void {

	std::cout << '\n';
	std::cout << "COUNT" << '\t' << "NAME" << '\t' << '\t' << "TIME" << '\n';
	size_t count = 1;
	for (auto i : v) {
		std::cout << count++ << '\t' << i.first << '\t' << i.second << '\n';
	};
	std::cout << '\n';

};


auto test_algorithm(std::function<void()> f) -> double {

	auto start = std::chrono::steady_clock::now();
	f();
	auto end = std::chrono::steady_clock::now();
	return std::chrono::duration<double>(end - start).count();

};
