    #include <iostream>
    #include <cmath>
    using namespace std;
    int main() {
       double a{numeric_limits<double>::max()};
       cout << a << endl; // 1.79769e+308
       double b{a};
       double c{(a + b) / 2};
       cout << c << endl;  // inf
       a = numeric_limits<double>::denorm_min();  // smallest denormalized number
       b = a;
       c = a / 2 + b / 2;
       cout << c << endl;  // 0
       // -> Unterlauf
    }
