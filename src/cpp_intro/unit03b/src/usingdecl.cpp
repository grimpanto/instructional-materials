#include <iostream>  // usingdecl.cpp
#include <vector>

int main() {
    // equiv to: using vector = std::vector;
    using std::vector;

    using std::cout;  // cout is no type!
    vector<int> vec{1, 2, 3};
    cout << vec.size() << std::endl;
}
