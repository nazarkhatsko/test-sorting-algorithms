#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <functional>


typedef std::pair<std::string, double> pair_t;


auto input(const std::string &) -> std::string;
auto print_result(const std::vector<pair_t> &) -> void;
auto test_algorithm(std::function<void()>) -> double;
