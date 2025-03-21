#include <iostream>  // span.cpp
#include <vector>
#include <array>
#include <span>

void print_content(std::span<int> container) {
    for(const auto &e : container) {
        std::cout << e << ' ';  }
    std::cout << '\n';
}
int main() {
    int arr[]{1, 2, 3, 4, 5};
    print_content(arr);  // 1 2 3 4 5
    std::vector v{1, 2, 3, 4, 5};
    print_content(v); //1 2 3 4 5
    std::array arr2{1, 2, 3, 4, 5};
    print_content({begin(arr2) + 1, end(arr2) - 2});
      // 2 3
}
