#include "estd.h"
#include <map>
using namespace Estd;  // map.cpp
#include "print_map.h"
int main() {
    map<string, int> pb{{"maxi",123},{"mini",999}};
    pb["otto"]=475; pb["maxi"]=112; print_map(pb);
    try {
        cout << pb.at("xxx") << endl;
    } catch (...) { cout << "not found! "; }
    cout << pb["xxx"] << ' ';
    cout << pb.at("xxx") << endl;  // found!
}
