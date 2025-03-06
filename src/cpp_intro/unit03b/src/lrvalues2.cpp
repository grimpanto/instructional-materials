#include <iostream>  // lrvalues2.cpp
using namespace std;

int main() {
    int i;
    i = 4;
    // 4 = i;  // error: lvalue required...
    (i + 1) = 5;  // error!
    const int j{6};  // j is an lvalue
    // j = 7;  // error!
}

int& h() {
  return 2; //error: invalid init...from an rvalue
}
