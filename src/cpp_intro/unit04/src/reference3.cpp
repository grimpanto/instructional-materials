#include <iostream>  // reference3.cpp
#include <string>
using namespace std;
int main() {
    string long_names[]{"maxi", "mini", "otto"};
    // find the appropriate type yourself
    // no change and no copy
    // → useful for long strings!
    for (const auto& name : long_names) {
        cout << name << endl;
    }
}
