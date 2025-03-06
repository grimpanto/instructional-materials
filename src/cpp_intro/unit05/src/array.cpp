#include <iostream>  // array.cpp
#include <array>
using namespace std;
int main() {
    array<int, 5> arr;
    cout << "size: " << arr.size() << endl;
    for (auto i : arr) {
        cout << i << " ";
    }
}
