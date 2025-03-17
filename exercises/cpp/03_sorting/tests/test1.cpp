// @copyright 2019 Günter Kolousek

#include "sorting.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>

using namespace std;

bool is_sorted(vector<int> nums) {
    int last{numeric_limits<int>::min()};
    for (size_t i{0}; i < nums.size(); ++i) {
        if (nums[i] >= last)
            last = nums[i];
        else
            return false;
    }
    return true;
}

TEST_CASE("testing bubblesort") {
    vector<int> nums{3, 1, 7, 0, 9, 8, 2, 4, 6, 5};

    sorting::bubble_sort(nums.size(), nums.data());
    CHECK(is_sorted(nums));
}

TEST_CASE("testing insertion-sort") {
    vector<int> nums{3, 1, 7, 0, 9, 8, 2, 4, 6, 5};

    sorting::selection_sort(nums.size(), nums.data());
    CHECK(is_sorted(nums));
}

TEST_CASE("testing selection-sort") {
    vector<int> nums{3, 1, 7, 0, 9, 8, 2, 4, 6, 5};

    sorting::selection_sort(nums.size(), nums.data());
    CHECK(is_sorted(nums));
}
