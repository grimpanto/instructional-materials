#include <iostream>  // functionoverloading3.cpp
using namespace std;
int incr(int counter) {
    cout << "int" << ' ';  return counter + 1;
}
int incr(double counter) {
    cout << "double" << ' '; return counter + 1;
}
int main() {
    int incr(double counter);  // declaration!
    incr(1); ::incr(1); }
