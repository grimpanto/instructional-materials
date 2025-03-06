#include <iostream>  // spaceship_operator4.cpp
#include <algorithm>
using namespace std;
struct CaseInsensitiveString;
using CIStr = CaseInsensitiveString;

struct CaseInsensitiveString {
  string v;
  weak_ordering operator<=>(const CIStr& other) const {
    string s1{v};  string s2{other.v};
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);
    return s1 <=> s2;
  }
  bool operator==(const CIStr& other) const {
    string s1{v};  string s2{other.v};
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);
    return s1 == s2;
  } };

int main() {
    CIStr s1{"abc"};
    CIStr s2{"aBC"};
    cout << (s1 == s2) << endl;  // 1
    cout << (s1 != s2) << endl;  // 0
    cout << (s1 < s2) << endl;  // 0
    cout << (s1 <= s2) << endl;  // 1
    cout << (s1 > s2) << endl;  // 0
    cout << (s1 >= s2) << endl;  // 1
}
