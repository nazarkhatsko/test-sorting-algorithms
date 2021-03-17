#pragma once

#include <vector>
#include <functional>
#include <algorithm>


typedef int num_t;
typedef std::vector<num_t> arr_t;
typedef std::function<bool(const num_t &, const num_t &)> comp_t;


// O(n^2) O(n^2) O(n)
void bubble_sort(arr_t &, comp_t);

// O(n^2) O(n^2) O(n^2)
void selection_sort(arr_t &, comp_t);

// O(n^2) O(n^2) O(n)
void insertion_sort(arr_t &, comp_t);

// O(n^2) O(n*log(n)) O(n*log(n))
void merge_sort(arr_t &, comp_t);

// O(n^2) O(n*log(n)) O(n*log(n))
void quick_sort(arr_t &, comp_t);

// O(n) O(n) O(n)
void counting_sort(arr_t &, comp_t);

// O(n^2) O(n^2) O(n*log(n))
void shell_sort(arr_t &, comp_t);
