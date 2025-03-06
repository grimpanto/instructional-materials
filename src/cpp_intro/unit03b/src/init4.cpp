#include <iostream>  // init4.cpp
#include <vector>
using namespace std;
int x;  // initialized with {}

int main() {
    int x;  // not initialized
    char buf[1024];  // not initialized

    int* p{new int};  // *p not initialized
    string s;  // s == ""
    vector<int> v;  // v == {}
    string* ps{new string};  // *ps == ""
}
