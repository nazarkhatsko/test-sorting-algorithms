#include "algorithms.hpp"

void bubble_sort(arr_t &a, comp_t f) {
    for (std::size_t i = 0; i < a.size() - 1; i++) {
        for (std::size_t j = 0; j < a.size() - i - 1; j++) {
            if (not f(a.at(j), a.at(j + 1))) {
                std::swap(a.at(j), a.at(j + 1));
            }
        }
    }
}

void selection_sort(arr_t &a, comp_t f) {
    for (std::size_t i = 0; i < a.size(); i++) {
        auto el = a.begin();
        for (std::size_t j = 1; j < a.size(); j++) {
            if (f(*el, a.at(j))) {
                el = a.begin() + j;
            }
        }
        std::swap(*el, a.at(i));
    }
}

void insertion_sort(arr_t &a, comp_t f) {
    for (std::size_t i = 1; i < a.size(); i++) {
        for (std::size_t j = i; j > 0; j--) {
            if (f(a.at(j), a.at(j - 1))) {
                std::swap(a.at(j), a.at(j - 1));
            }
        }
    }
}

void merge_sort(arr_t &a, comp_t f) {
    if (a.size() <= 1) {
        return;
    }

    std::size_t n = a.size() / 2;
    arr_t left(a.begin(), a.begin() + n);
    arr_t right(a.begin() + n, a.end());

    merge_sort(left, f);
    merge_sort(right, f);

    a.clear();

    std::size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (f(left.at(i), right.at(j))) {
            a.push_back(left.at(i));
            i++;
        } else {
            a.push_back(right.at(j));
            j++;
        }
    }

    if (i < left.size()) {
        a.insert(a.end(), left.begin() + i, left.end());
    } else if (j < right.size()) {
        a.insert(a.end(), right.begin() + j, right.end());
    }
}

void quick_sort(arr_t &a, comp_t f) {
    if (a.size() <= 1) {
        return;
    }

    arr_t left;
    arr_t center;
    arr_t right;

    for (std::size_t i = 0; i < a.size(); i++) {
        if (f(a.at(0), a.at(i))) {
            right.push_back(a.at(i));
        } else if (a.at(0) == a.at(i)) {
            center.push_back(a.at(i));
        } else {
            left.push_back(a.at(i));
        }
    }

    quick_sort(left, f);
    quick_sort(right, f);

    a.clear();
    a.insert(a.end(), left.begin(), left.end());
    a.insert(a.end(), center.begin(), center.end());
    a.insert(a.end(), right.begin(), right.end());
}

void shell_sort(arr_t &a, comp_t f) {
    int gap = a.size() / 2;
    while (gap > 0) {
        for (int i = gap; i < a.size(); i++) {
            int j = i;
            int temp = a.at(i);
            while (j >= gap && !f(a.at(j - gap), temp)) {
                a.at(j) = a.at(j - gap);
                j -= gap;
            }
            a.at(j) = temp;
        }
        gap /= 2;
    }
}
