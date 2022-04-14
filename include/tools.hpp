#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <random>
#include <functional>

using result_t = std::vector<std::pair<std::string, double>>;

std::string      input          (const std::string &s);
double           execution_time (std::function<void()> f);
void             sort_result    (result_t &r);
void             print_result   (const result_t &r);
std::vector<int> generate_array (std::size_t size, int a, int b);
