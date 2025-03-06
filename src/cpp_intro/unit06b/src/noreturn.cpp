#include <cstdlib>  // fallthrough.cpp
#include <string>
using namespace std;

// UB if f() returns!
[[noreturn]] void f(bool x){
    if (x)
       throw "error";
}

[[noreturn]] void usage(std::string msg) {
    std::exit(1);
}

int main() {
}
