
#include <functional>

class Sample {  // clang++ and Visual C++
  public: 
    class {
        int value;
      public:
        int& operator=(const int& val) { return value = (val < 0) ? 0 : val; }
        operator int() const { return value; }
    } length;
};

#include <iostream>
using namespace std;

int main() {
    Sample obj;
    obj.length = 100;
    cout << obj.length << endl;
}
