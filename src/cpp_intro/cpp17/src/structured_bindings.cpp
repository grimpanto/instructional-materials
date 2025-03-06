#include <iostream>  // structured_bindings.cpp
using namespace std;
int main() {
   int arr[2]{1, 1};

   // creates an array int tmp[2]
   // copies arr into tmp
   // x == &tmp[0], y == &tmp[1]
   auto [x, y]{arr};
   arr[0] = 2;
   cout << x << endl;  // -> 1

   // xr == &arr[0], yr == &arr[1]
   auto& [xr, yr] = arr;
   arr[0] = 3;
   cout << xr << endl;  // -> 3
}
