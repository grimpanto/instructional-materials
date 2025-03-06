#include <iostream>  // nontype_template_parameter.cpp
using namespace std;

// has to be a 'structural type'
struct X {
  X()=default;
  constexpr X(int i) : i{i} {}
  int i{};  // no private, no mutable
};

template <X x>
auto get_X() {
    return x;
}

int main() {
    X x;
    cout << get_X<X{123}>().i << endl;  // -> 123
    cout << get_X<1>().i << endl; //implicit conversion
}
