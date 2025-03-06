#include <iostream>  // variables_for.cpp
#include <vector>
using namespace std;

int main() {
    vector<int> v{1, 1, 2, 3, 5, 8, 13};
    for (int sum{0}; auto value : v) {
        sum += value;
        cout << sum << endl;
    }
    // cout << sum << endl;  // sum not declared...
}
