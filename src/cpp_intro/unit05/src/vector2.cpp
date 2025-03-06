#include "estd.h"
#include <vector>
using namespace Estd;  // vector2.cpp
int main() {  vector<string> v1{"apple", "orange"};
    vector<string> v2{"plum", "apricot"};
    v1.insert(v1.begin()+1,"banana");//before pos 1
    v1.insert(v1.begin()+2, v2.begin(), v2.end());
    print(v1);
    cout << v1.size() << ' ' <<v1.capacity()<<endl;
    v1.shrink_to_fit();
    cout << v1.size() << ' ' <<v1.capacity()<<endl;
}
