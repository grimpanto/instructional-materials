#include <iostream>  // class_template_deduction.cpp
#include <vector>
#include <utility>  // pair
using namespace std;
int main() {
    vector v{1, 2, 3, 4};  // vector<int>
    pair p{1, 2.5};  // pair<int, double>

    cout << p.first << ' ' << p.second << endl;
}
