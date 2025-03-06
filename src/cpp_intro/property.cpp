
class Sample {  // clang++ and Visual C++
  private:
    int _length; 
  public: 
    __declspec(property(put=set_length, get=get_length)) 
    int length;
    void set_length (int val) { _length = (val < 0) ? 0 : val; }
    int get_length() const {
        return _length ; 
    } 
};

#include <iostream>
using namespace std;

int main() { 
    Sample obj;
    obj.length = 100;
    cout << obj.length << endl; 
} 
