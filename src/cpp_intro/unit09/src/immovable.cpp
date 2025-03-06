#include <iostream>  // immovable.cpp
using namespace std;
struct Immovable {
    Immovable() {}
    Immovable(const Immovable&)=delete;
    Immovable& operator=(const Immovable& o)=delete;
  // explicitly not copyable -> not moveable as well
  // in case you want to be explicit... feel free!
};
int main() {
    Immovable i;
    // i = Immovable{};  not possible any more
}
