#include <iostream>  // init3.cpp
#include <vector>
using namespace std;

int main() {
    vector<int> v1(10);
    cout << v1.size() << " " << v1[0] << endl;
    vector<int> v2(1, 10);
    cout << v2.size() << " " << v2[0] << endl;
    //vector<int> v3{1, 10}; // <=C++14
    vector v3{1, 10};  // since C++17 possible
    cout << v3.size() << " " << v3[0] << endl;
}
