#include <iostream>
#include <algorithm>
using namespace std;
class Data {  // lvalue_vs_rvalue.cpp
    char* data;
    size_t size;
  public:
    // be aware of dangling pointer!
    Data(char* data, size_t size) : data{data}, size{size} {}
    char* get_data() const& {  // will be called on lvalue
        char* result{new char[size]};
        copy_n(data, size, result);
        return result;
    }
    char* get_data() && {  // will be called on rvalue
        char* tmp{data};
        data = nullptr;
        size = 0;
        return tmp;
    }
};

int main() {
    Data d1{const_cast<char*>("abc"), 4};
    char* cstr{d1.get_data()};
    cstr[1] = 'x';  cout << cstr << endl;  // -> axc
    delete[] cstr;
    char* cstr2{Data{const_cast<char*>("abc"), 4}.get_data()};
    //cstr2[1] = 'x';  does not work any more (it's read-only)
    cout << cstr2 << endl;  // -> abc
    // no delete here!!!
}
