#include <iostream>  // ranges.cpp
#include <vector>
#include <ranges>
using namespace std;

auto square = [](int val) { return val * val; };
auto is_over2 = [](int val) { return val > 2; };

void print_over2(ranges::range auto r) {
    for (int i : r | ranges::views::transform(square)
                   | ranges::views::filter(is_over2)) {
        cout << "square over 2: " << i << endl;
    }
}

int main() {
    vector<int> v{1,2,3};
    print_over2(v);
}
