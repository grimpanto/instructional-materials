#include <iostream>  // pointer2.cpp
using namespace std;
int main(int argc, char* argv[]) {
    int age{42};
    int* p{nullptr};  // formerly: int* p{0};
    // shorter: int* p{};
    // age = nullptr;  // error!
    p = &age;
    p = new int[10]{};  // initialized!
    cout << p[5] << endl;  // 0
    int* q;  // not initialized
    q = p;  // assignement
    cout << *q << endl;  // 0
    p = 0;  // possible but not recommended
    delete[] q;  // it's an array!
}
