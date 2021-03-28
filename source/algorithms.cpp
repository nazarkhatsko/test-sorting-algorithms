#include "algorithms.hpp"


void bubble_sort(std::vector<data_t> &v, comp_t f) {

	for (std::size_t i = 0; i < v.size() - 1; i++) {
		for (std::size_t j = 0; j < v.size() - i - 1; j++) {
			if (!f(v.at(j), v.at(j + 1))) {
				std::swap(v.at(j), v.at(j + 1));
			};
		};
	};

};


void selection_sort(std::vector<data_t> &v, comp_t f) {

	for (std::size_t i = 0; i < v.size(); i++) {
		auto el = v.begin();
		for (std::size_t j = 1; j < v.size(); j++) {
			if (f(*el, v.at(j))) {
				el = v.begin() + j;
			};
		};
		std::swap(*el, v.at(i));
	};

};


void insertion_sort(std::vector<data_t> &v, comp_t f) {

	for (std::size_t i = 1; i < v.size(); i++) {
		for (std::size_t j = i; j > 0; j--) {
			if (f(v.at(j), v.at(j - 1))) {
				std::swap(v.at(j), v.at(j - 1));
			};
		};
	};

};


void merge_sort(std::vector<data_t> &v, comp_t f) {

	if (v.size() <= 1) {
		return;
	};

	std::size_t n = v.size() / 2;
	std::vector<data_t> left(v.begin(), v.begin() + n);
	std::vector<data_t> right(v.begin() + n, v.end());

	merge_sort(left, f);
	merge_sort(right, f);

	v.clear();

	std::size_t i = 0, j = 0;
	while (i < left.size() && j < right.size()) {
		if (f(left.at(i), right.at(j))) {
			v.push_back(left.at(i));
			i++;
		} else {
			v.push_back(right.at(j));
			j++;
		};
	};

	if (i < left.size()) {
		v.insert(v.end(), left.begin() + i, left.end());
	} else if (j < right.size()) {
		v.insert(v.end(), right.begin() + j, right.end());
	};

};


void quick_sort(std::vector<data_t> &v, comp_t f) {

	if (v.size() <= 1) {
		return;
	};

	std::vector<data_t> left;
	std::vector<data_t> center;
	std::vector<data_t> right;

	for (std::size_t i = 0; i < v.size(); i++) {
		if (f(v.at(0), v.at(i))) {
			right.push_back(v.at(i));
		} else if (v.at(0) == v.at(i)) {
			center.push_back(v.at(i));
		} else {
			left.push_back(v.at(i));
		};
	};

	quick_sort(left, f);
	quick_sort(right, f);

	v.clear();
	v.insert(v.end(), left.begin(), left.end());
	v.insert(v.end(), center.begin(), center.end());
	v.insert(v.end(), right.begin(), right.end());

};


void shell_sort(std::vector<data_t> &v, comp_t f) {

	int gap = v.size() / 2;
	while (gap > 0) {
		for (int i = gap; i < v.size(); i++) {
			int j = i;
			int temp = v.at(i);
			while (j >= gap && !f(v.at(j - gap), temp)) {
				v.at(j) = v.at(j - gap);
				j -= gap;
			};
			v.at(j) = temp;
		};
		gap /= 2;
	};

};
