#include <iostream>  // lambdageneric.cpp
using namespace std;
int main() {
    auto f = [](auto x){ return x; };
    cout << f(1) << ' ';
    cout << f("abc") << ' ';
    cout << f(false) << endl;
}

#include <iostream>  // lambdageneric.cpp
using namespace std;
int main() {
    // arbitrary types but must be convertible
    auto f = [](auto x, decltype(x) y){
        return x + y;
    };
    cout << f(1, 2) << ' ';
    cout << f(3.5, 2) << ' ';
    cout << f(2, 3.5) << ' ';
    cout << f(string{"a"}, "bc") << endl;
}
