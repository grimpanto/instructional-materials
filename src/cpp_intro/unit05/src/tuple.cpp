#include <iostream>  // tuple.cpp
#include <tuple>
using namespace std;
using namespace std::literals;  // can be ommitted (maybe...)
int main() {
  auto key{make_tuple(1234,"Maxi Muster"s,'A')};
  get<0>(key) = 4711;  // look it will be modified
  // error if multiple identical types:
  cout << '(' << get<int>(key) << ", "
       << get<string>(key) << ", "
       << get<char>(key) << ')';
  int id;   string name;  char type;
  tie(id, name, type) = key; // tuple unpacking...
}
