#include "algorithms.hpp"


void bubble_sort(std::vector<int> &v) {

	for (int i = 0; i < v.size() - 1; i++) {
		for (int n = 0; n < v.size() - i - 1; n++) {
			if (v.at(n) > v.at(n + 1)) {
				std::swap(v.at(n), v.at(n + 1));  
			};
		};
	};

};


void selection_sort(std::vector<int> &v) {

	for (int i = 0; i < v.size(); i++) {
		auto it = std::min_element(v.begin() + i, v.end());
		std::swap(*it, v.at(i));
	};

};


void insertion_sort(std::vector<int> &v) {

	for (int i = 0; i < v.size(); i++) {
		for (int n = 0; n < v.size(); n++) {
			if (v.at(i) < v.at(n)) {
				std::swap(v.at(i), v.at(n));
			};
		};
	};

};


void counting_sort(std::vector<int> &v) {

	int max = *std::max_element(v.begin(), v.end());
    int min = *std::min_element(v.begin(), v.end());
    int range = max - min + 1;
 
    std::vector<int> count(range);
    for (int i = 0; i < v.size(); i++) {
        count.at(v.at(i) - min)++;
    };
 
    for (int i = 1; i < count.size(); i++) {
        count.at(i) += count.at(i - 1);
    };
 
 	std::vector<int> output(v.size());
    for (int i = v.size() - 1; i >= 0; i--) {
        output.at(count.at(v.at(i) - min) - 1) = v.at(i);
        count.at(v.at(i) - min)--;
    };
 
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = output.at(i);
    };

};


void shell_sort(std::vector<int> &v) {

	for (int gap = v.size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < v.size(); i++) {
			int j;
			for (j = i; j >= gap && v[j - gap] > v[i]; j -= gap) {
				v[j] = v[j - gap];
			};
			v[j] = v[i];
		};
	};

};
