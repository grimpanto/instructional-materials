
#include <iostream>
#include <bitset>

using namespace std;

int main() {
    unsigned char ub{1};
    // the following declarations yields to a warning: narrowing conversion
    // because type of ~ub is an int!
    // bitset<8> bs2{~ub};
    // so this has to be coded, but...
    bitset<8> bs_ub{static_cast<unsigned char>(~ub)};
    cout << "unsigned char ub{1};" << endl;
    cout << "one complement of ub: " << bs_ub << endl;
    // ub will be implicitly converted (promoted) to an int beforehand:
    cout << "~ub: " << ~ub << endl;
    cout << "~1: " << ~1 << endl;

    cout << endl;
    
    unsigned int ui{1};
    bitset<32> bs_ui{~ui};
    cout << "unsigned int ui{1}" << endl;
    cout << "one complement of ui: " << bs_ui << endl;
    cout << "~ui: " << ~ui << " !!!" << endl;
    cout << "~1: " << ~1 << endl;
}
