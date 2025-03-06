#include <iostream>  // string.cpp

using namespace std;
int main() {
    string s{"https://www.htlwrn.ac.at"};
    cout << s.starts_with("https") << endl;  // 1
    string s2{"https"};
    cout << s.starts_with(s2) << endl;  // 1
    string_view sv{".at"};
    cout << s.ends_with(sv) << endl;  // 1
    cout << sv.ends_with('t') << endl;  // 1
}
