#include <iostream>  // typealias.cpp
#include <vector>
using namespace std;

int main() {
    using IntStack = std::vector<int>;
    IntStack stack{};
    stack.push_back(1); stack.push_back(2);
    cout << stack.back() << endl;
    stack.pop_back();
    cout << stack.back() << endl;
    stack.pop_back();
}
