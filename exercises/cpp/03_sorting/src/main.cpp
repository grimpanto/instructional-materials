// @copyright 2019 Günter Kolousek

#include "sorting.h"

#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#define FMT_HEADER_ONLY
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char** argv) {
    CLI::App app{"Sorts the given sequenz of numbers"};

    vector<int> nums;

    string algo{"bubble"};

    bool bubble{false};
    bool insertion{true};
    bool selection{false};

    auto algorithm{app.add_option_group("algorithm", "Choose the preferred sorting algorithm")};
    algorithm->add_flag("-b,--bubble", bubble, "Use bubblesort");
    algorithm->add_flag("-i,--insertion", insertion, "Use insertion sort (default)");
    algorithm->add_flag("-s,--selection", selection, "Use selection sort");
    algorithm->require_option(0, 1);

    app.add_option("NUMBERS", nums, "The numbers to sort")->required();

    app.get_formatter()->label("OPTIONS", "Options");

    CLI11_PARSE(app, argc, argv);

    if (bubble)
        sorting::bubble_sort(nums.size(), nums.data());
    else if (selection)
        sorting::selection_sort(nums.size(), nums.data());
    else if (insertion)
        sorting::insertion_sort(nums.size(), nums.data());

    fmt::print("{}", nums);
    return 0;
}
