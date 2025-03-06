#include <iostream>
#include <initializer_list>

using namespace std;

int main() {
    auto a={1, 2, 3};  // initializer_list<int>
    for (auto e : a) cout << e << ' ';
    auto b={4};
    for (auto e : b) cout << e << ' ';
    auto c{42};
    cout << c << endl;
    // auto d{1, 2, 3};  // error!
}
