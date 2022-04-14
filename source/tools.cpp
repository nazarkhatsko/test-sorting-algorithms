#include "tools.hpp"

std::string input(const std::string &s) {
    std::cout << s;
    std::string r;
    std::cin >> r;
    return r;
}

double execution_time(std::function<void()> f) {
    auto start = std::chrono::steady_clock::now();
    f();
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(end - start).count();
}

void sort_result(result_t &r) {
    std::sort(r.begin(), r.end(), [](const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {
        return a.second < b.second;
    });
}

void print_result(const result_t &r) {
    std::cout << "\n";
    std::cout << "COUNT\tNAME\t\tTIME\n";
    std::size_t count = 1;
    for (const auto &[key, value] : r) {
        std::cout << count++ << "\t" << key << "\t" << value << "s\n";
    }
    std::cout << "\n";
}

std::vector<int> generate_array(std::size_t size, int a, int b) {
    auto v = std::vector<int>(size);
    auto dre = std::default_random_engine();
    auto uid = std::uniform_int_distribution<int>(a, b);
    for (auto &i : v) {
        i = uid(dre);
    }
    return v;
}