#include <iostream>  // func_obj2.cpp
#include <functional>
using namespace std;
using namespace std::placeholders;  // _1, _2,...
int sub(int a, int b) { return a - b; }

int main() {
    auto answer = bind(sub, 43, 1);
    cout << answer() << ' ';
    auto decr = bind(sub, _1, 1);  // first of decr
    cout << decr(43) << ' ';
    auto subinv = bind(sub, _2, _1);
    cout << subinv(1, 43) << endl;;
}
