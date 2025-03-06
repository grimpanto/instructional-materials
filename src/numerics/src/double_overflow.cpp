  #include <iostream>
  #include <limits>
  #include <cmath>
  using namespace std;
  
  int main() {
     double x{};
     x = numeric_limits<double>::max();
     cout << x << " is inf: " << isinf(x) << endl;
     // -> 1.79769e+308 is inf: 0
     x = numeric_limits<double>::infinity();
     cout << x << " is inf: " << isinf(x) << endl;
     // -> inf is inf: 1
     cout << x + 1 << endl;  // -> inf
  }
