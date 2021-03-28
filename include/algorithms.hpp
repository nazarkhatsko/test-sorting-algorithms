#pragma once

#include <vector>
#include <functional>
#include <algorithm>


using data_t = int;
using comp_t = std::function<bool(const data_t &, const data_t &)>;


// O(n^2) O(n^2) O(n)
void bubble_sort(std::vector<data_t> &, comp_t);

// O(n^2) O(n^2) O(n^2)
void selection_sort(std::vector<data_t> &, comp_t);

// O(n^2) O(n^2) O(n)
void insertion_sort(std::vector<data_t> &, comp_t);

// O(n^2) O(n*log(n)) O(n*log(n))
void merge_sort(std::vector<data_t> &, comp_t);

// O(n^2) O(n*log(n)) O(n*log(n))
void quick_sort(std::vector<data_t> &, comp_t);

// O(n^2) O(n^2) O(n*log(n))
void shell_sort(std::vector<data_t> &, comp_t);
