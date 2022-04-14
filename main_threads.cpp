#include "tools.hpp"
#include "algorithms.hpp"

#include <thread>

double wrapper_for_thread(std::function<void(arr_t &, comp_t)> f, const arr_t &a, const comp_t c) {
    const auto r = execution_time([&]() {
        auto copy = arr_t(a);
        f(copy, c);
    });
    return r;
}

int main() {
    std::cout << std::fixed;
    std::cout << "TSA (Test Sorting Algorithms)\n";
    std::cout << "Version 1.2\n";
    std::cout << "\n";

    const auto size       = std::stoi(input("Enter size: "));
    const auto min        = std::stoi(input("Enter min: "));
    const auto max        = std::stoi(input("Enter max: "));
    const auto array      = generate_array(size, min, max);
    const auto comparison = [](const int &a, const int &b) {
        return a < b;
    };

    auto result = result_t({
        {"bubble sort",    0.0},
        {"selection sort", 0.0},
        {"insertion sort", 0.0},
        {"merge sort",     0.0},
        {"quick sort",     0.0},
        {"shell sort",     0.0}
    });

    const auto total_time = execution_time([&]() {
        auto threads = std::vector<std::thread>(6);
        threads[0] = std::thread([&]() { result[0].second = wrapper_for_thread(bubble_sort, array, comparison); });
        threads[1] = std::thread([&]() { result[1].second = wrapper_for_thread(selection_sort, array, comparison); });
        threads[2] = std::thread([&]() { result[2].second = wrapper_for_thread(insertion_sort, array, comparison); });
        threads[3] = std::thread([&]() { result[3].second = wrapper_for_thread(merge_sort, array, comparison); });
        threads[4] = std::thread([&]() { result[4].second = wrapper_for_thread(quick_sort, array, comparison); });
        threads[5] = std::thread([&]() { result[5].second = wrapper_for_thread(shell_sort, array, comparison); });

        for (auto &i : threads) {
            if (i.joinable()) {
                i.join();
            }
        }
    });
    
    sort_result(result);
    print_result(result);

    std::cout << "Total time: " << total_time << " seconds\n";

    return EXIT_SUCCESS;
}
