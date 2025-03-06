#include <iostream>  // estd.h
#include <algorithm>
namespace Estd {
    using namespace std;
    template <typename T>
    void print(T& seq) {
        for (const auto& s : seq) {
            cout << s << ' '; }
        cout << endl;
    }
    template <typename T>
    void sort(T& seq) {
        std::sort(begin(seq), end(seq));
    }
}
