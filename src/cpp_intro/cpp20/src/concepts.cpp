#include <iostream>  // concepts.cpp
#include <vector>
using namespace std;
template <typename T>
concept IsContainer = requires(const T& t) {
    { t.begin() }; // better: use free function begin()
    { t.end() };  };
// like a function template for arbitrary type
void print_coll(const IsContainer auto& coll) {
    for (const auto& elem : coll) {
        std::cout << elem << '\n';
    } }
int main() {
    vector<int> v{1,2,3};  print_coll(v);
//    int a[]{1,2,3};  print_coll(a);
//      neither begin() nor end() as member!
//      will work if you're using free functions
    string s{"123"};  print_coll(s);
}
