
#include <functional>

template <typename T> class property {
    using SetFunc=std::function<T(T)>;
    using GetFunc=std::function<T(T)>;
    T value;
    SetFunc setter;
    GetFunc getter;
  public:
    property(SetFunc setter, GetFunc getter) : setter{setter}, getter{getter} {};
    T & operator= (const T &i) {
        return value = setter(i);
    }
    // assignment to this is only possible with exact identical types
    template<typename T2> T2 & operator= (const T2& i) {
        T2 &guard = value;
        throw guard;  // never reached
    }
    operator T() const {
        return getter(value);
    }
};


class Sample {  // clang++ and Visual C++
  public: 
    property<int> length{ [](int val) { return (val < 0) ? 0 : val; },
                          [](int val) { return val; }};
};

#include <iostream>
using namespace std;

int main() {
    Sample obj;
    obj.length = 100;
    cout << obj.length << endl;
}
