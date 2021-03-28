#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <functional>


using pair_t = std::pair<std::string, double>;


std::string input(const std::string &);
void print_result(const std::vector<pair_t> &);
double test_algorithm(std::function<void()>);
