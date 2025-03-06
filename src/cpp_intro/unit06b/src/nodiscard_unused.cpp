#include <iostream>  // nodiscard_unused.cpp
using namespace std;

[[nodiscard]]
int f(int x) { return x; }

// warning: unused parameter...
void g(int y) { cout << 42 << endl; }

void h([[maybe_unused]] int y) { cout<<42<<endl; }

int main() {
    f(42);  // warning: ignoring return value...
    g(1);
    h(1);
}
