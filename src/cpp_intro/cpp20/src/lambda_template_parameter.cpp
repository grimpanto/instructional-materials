#include <iostream>  // lambda_template_parameter.cpp
using namespace std;
int main() {
    // arbitrary types but must be identical
    auto f = []<typename T>(T x, T y){
        return x + y;
    };
    cout << f(1, 2) << ' ';
    cout << f(3.5, 2.5) << ' ';
    // cout << f(3.5, 2) << ' '; //no match for call...
    cout << f(string{"a"}, string{"bc"}) << endl;
}
