#include <iostream>  // array5.cpp
#include <array>
using namespace std;
int main() {
    array<int, 5> arr{1, 2, 3};
    array<int, 5> arr2;

    arr2 = arr;
    if (arr == arr2)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
}
