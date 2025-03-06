#include <iostream>  // pair.cpp
#include <utility>
using namespace std;
using namespace std::literals;  // can be ommitted (maybe...)
int main() {
    auto key{make_pair(1234, "Maxi Muster"s)};
    get<0>(key) = 4711;  // look it will be modified
    cout << '(' << key.first << ", "
                << key.second << ')' << endl;
    // error if multiple identical types:
    cout << '(' << get<0>(key) << ", "
                << get<string>(key) << ')';
    int id;
    string name;
    tie(id, name) = key;
    cout << endl << id << ", " << name;
}
