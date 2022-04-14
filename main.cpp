#include "tools.hpp"
#include "algorithms.hpp"

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

    const auto total_time = execution_time([&]() {
        auto result = result_t({
            {"bubble sort",    execution_time(std::bind(bubble_sort, array, comparison))},
            {"selection sort", execution_time(std::bind(selection_sort, array, comparison))},
            {"insertion sort", execution_time(std::bind(insertion_sort, array, comparison))},
            {"merge sort",     execution_time(std::bind(merge_sort, array, comparison))},
            {"quick sort",     execution_time(std::bind(quick_sort, array, comparison))},
            {"shell sort",     execution_time(std::bind(shell_sort, array, comparison))}
        });
        sort_result(result);
        print_result(result);
    });

    std::cout << "Total time: " << total_time << " seconds\n";

    return EXIT_SUCCESS;
}
