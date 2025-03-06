#include <iostream>  // lambdacapturemove.cpp
#include <memory>
using namespace std;
int main() {
    // doesn't have to exist; type will be inferred
    cout << [x=1]{ return x; }() << ' ';
    // can now be an rvalue!
    std::unique_ptr<double> pi(new double{3.14});
    cout << [x=move(pi)](){ return *x; }() << ' ';
    int y{1};  auto h = [y=0]{ return y; };
    cout << h() << ' ' << y << endl;
}
