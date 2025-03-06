#include "estd.h"
#include <vector>
using namespace Estd;  // vector3.cpp
int main() {
    vector<string> v1{"apple","banana","plum",
        "apricot","orange"};
    sort(begin(v1), end(v1));   print(v1);
    cout << v1.front() << ' ' << v1.back() << endl;
    v1.erase(begin(v1));  v1.pop_back();
    cout << v1.front() << ' ' << v1.back() << endl;
    v1.clear();  cout << v1.empty() << endl;
}
