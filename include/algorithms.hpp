#pragma once

#include <vector>
#include <functional>
#include <algorithm>

using arr_t = std::vector<int>;
using comp_t = std::function<bool(const int &, const int &)>;

void bubble_sort    (arr_t &a, comp_t f); // O(n^2) O(n^2) O(n)
void selection_sort (arr_t &a, comp_t f); // O(n^2) O(n^2) O(n^2)
void insertion_sort (arr_t &a, comp_t f); // O(n^2) O(n^2) O(n)
void merge_sort     (arr_t &a, comp_t f); // O(n^2) O(n*log(n)) O(n*log(n))
void quick_sort     (arr_t &a, comp_t f); // O(n^2) O(n*log(n)) O(n*log(n))
void shell_sort     (arr_t &a, comp_t f); // O(n^2) O(n^2) O(n*log(n))
