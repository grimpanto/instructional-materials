#include <iostream>  // auto_wo_lambda.cpp
#include <vector>
using namespace std;

// like a function template for arbitrary type
void print_coll(const auto& coll) {
    for (const auto& elem : coll) {
        std::cout << elem << '\n';
    }
}

int main() {
    vector<int> v{1,2,3};
    print_coll(v);
    int a[]{1,2,3};
    print_coll(a);
    string s{"123"};
    print_coll(s);
}
