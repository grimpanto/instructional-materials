#include "estd.h"
#include <set>
using namespace Estd;  // set.cpp
int main() {
    set<int> s1{2, 1, 2, 1, 3, 4};
    print(s1);
    auto search = s1.find(2);  // iterator...
    if (search != s1.end())
        cout << "Found " << (*search) << endl;
    else
        cout << "Not found"  << endl;
    // insert, erase, clear, empty, size, begin&end
}
