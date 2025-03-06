#include <iostream>  // copy_elision.cpp
using namespace std;

struct Data {
   Data()=default;
   Data(const Data&) {
       cout << "copy cons" << endl; }
   int a;
   double b;
};

Data f() {
    return Data{};
}
int main() {
    Data d{f()};  // *no* output at all
}
