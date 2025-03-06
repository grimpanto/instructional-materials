#include <iostream> // spaceship_operator3.cpp
#include <unordered_set>
#include <algorithm>
using namespace std;
struct Set {
  unordered_set<int> v;
  partial_ordering operator<=>(const Set& o) const {
      if (v == o.v)
          return partial_ordering::equivalent;
      else if (includes(v.begin(), v.end(),
                 o.v.begin(), o.v.end()))
          return partial_ordering::less;
      else if (includes(o.v.begin(), o.v.end(),
                 v.begin(), v.end()))
          return partial_ordering::greater;
      return partial_ordering::unordered;
  }
  bool operator==(const Set& o) const {
      return (*this <=> o) == 0;
  } };

int main() {
    Set s1{{1, 2, 3}};
    Set s2{{2, 3, 4}};
    cout << (s1 == s2) << endl;  // 0
    cout << (s1 != s2) << endl;  // 1
    cout << (s1 < s2) << endl;  // 0
    cout << (s1 <= s2) << endl;  // 0
    cout << (s1 > s2) << endl;  // 0
    cout << (s1 >= s2) << endl;  // 0
}
