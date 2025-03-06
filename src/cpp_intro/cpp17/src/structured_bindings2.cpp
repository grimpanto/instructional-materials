#include <iostream>  // structured_bindings2.cpp
#include <tuple>
using namespace std;
int main() {
    int x{1};
    float y{2.5};
    string z{"abc"};
 
    const auto& [a, b, c]{
      tuple<int, float&, string>{x, y, move(z)}};
    
    cout<< a <<' '<< b <<' '<< c <<endl;//1 2.5 abc
    // a = 0;  //-> const!
    x = 42;
    cout << "a=" << a << endl;  // -> 1
    b = 3.5;
    cout << "y=" << y << endl;  // -> 3.5
    // c[0] = "x";  -> const!
    cout << "z='" << z << "'" << endl;  // -> ''
}
