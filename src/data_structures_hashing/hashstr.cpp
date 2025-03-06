
#include <iostream>

using namespace std;

int hash_str_python(string s, int m) {
    if (!s.size())
        return 0;
    int val{s[0]};
    for (char c : s) {
        val = (1000003 * val) ^ c;
    }
    return (val ^ s.size()) & (2 ^ m - 1);
}

int main() {
    cout << hash_str_python("value_or_not_value?", 4) << endl;
}
