#include <iostream>  // array2.cpp
#include <array>
using namespace std;
int main() {
    array<int, 5> arr{1, 2, 3};
    cout << "size: " << arr.size() << endl;
    for (auto i : arr) {
        cout << i << " ";
    }
}
