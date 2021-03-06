#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <chrono>
#include <functional>


auto input(const std::string &) -> std::string;
auto gen_rand_vec(long int, int, int) -> std::vector<int>;
auto print_result(const std::vector<std::pair<std::string, double>> &) -> void;
auto test_algorithm(std::vector<int>, std::function<void(std::vector<int> &)>) -> double;
