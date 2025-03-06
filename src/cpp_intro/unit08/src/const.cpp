#include <iostream>
using namespace std;
class Data {  // const.cpp
    string data;
  public:
    Data(string data) : data{data} {}
    char* get_raw() { return data.data(); }
    // overloaded method:
    char const* get_raw() const { return data.data(); }
};
int main() {
    Data d1{"abc"};
    char* cstr{d1.get_raw()};
    cstr[1] = 'x';  cout << cstr << endl;  // -> axc
    const Data d2{"abc"};
    // invalid conversion from ‘const char*’ to ‘char*’:
    //cstr = d2.get_raw();  
    const char* cstr2{d2.get_raw()};
}
