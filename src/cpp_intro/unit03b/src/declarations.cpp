#include <iostream>  // declarations.cpp
using namespace std;
constexpr double get_r() {
  return 3;
}

struct User; // no definition: just a declaration!
extern int err_nr;  // no definition

int main() {
    char ch;
    auto cnt{1};
    const double e{2.7182};
    constexpr double pi{3.1415};
    constexpr double U{2 * get_r() * pi};
}
