#include <iostream>  // classinit.cpp
using namespace std;

struct Distance {
    int len;
    Distance() {}  // user-declared and defined!
};
struct Distance2 {
    int len;
    Distance2()=default;  // you are free to choose...
};
int main() {
    Distance d1;
    Distance d2{};
    cout << d1.len << ", " << d2.len << endl;
    Distance2 d3;
    Distance2 d4{};
    cout << d3.len << ", " << d4.len << endl;
}
