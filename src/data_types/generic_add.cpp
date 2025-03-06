
#include <iostream>

using namespace std;

template <typename T>
T add(T x, T y) { return x + y; }
    
int main() {
    cout << add(1, 2) << endl;
    cout << add(1.0, 2.0) << endl;
    cout << add(string{"abc"}, string{"def"}) << endl;
}
