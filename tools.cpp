#include "tools.hpp"


auto input(const std::string &s) -> std::string {

	std::cout << s;
	std::string r;
	std::cin >> r;
	return (r);

};


auto gen_rand_vec(long int size, int a, int b) -> std::vector<int> {

	std::vector<int> v(size);
	std::default_random_engine gen;
	std::uniform_int_distribution<int> db(a, b);
	for (auto &i : v) {
		i = db(gen);
	};
	return (v);

};


auto print_result(const std::vector<std::pair<std::string, double>> &v) -> void {

	std::cout << '\n';
	std::cout << "COUNT" << '\t' << "NAME" << '\t' << '\t' << "TIME" << '\n';
	int count = 1;
	for (auto i : v) {
		std::cout << count++ << '\t' << i.first << '\t' << i.second << '\n';
	};
	std::cout << '\n';

};


auto test_algorithm(std::vector<int> v, std::function<void(std::vector<int> &)> f) -> double {

	auto start = std::chrono::steady_clock::now();
	f(v);
	auto end = std::chrono::steady_clock::now();
	return (std::chrono::duration<double>(end - start).count());

};
