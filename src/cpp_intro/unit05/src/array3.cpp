#include <iostream>  // array3.cpp
#include <array>
using namespace std;
int main() {
    array<int, 5> arr{1, 2, 3};
    // abort or value arbitrary!
    cout << arr[10] << endl;
    cout << arr.at(10) << endl;   // exception!
}
