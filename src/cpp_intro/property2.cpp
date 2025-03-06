template<typename T, typename C>
class Property {
  public:
    using SetterType = void (C::*)(T);
    using GetterType = T (C::*)() const;

    Property(C* obj, SetterType setter, GetterType getter)
      : obj{obj}, setter{setter}, getter{getter} { }

    operator T() const {
        return (obj->*getter)();
    }

    C& operator = (T theValue) {
        (obj->*setter)(theValue);
        return *obj;
    }

  private:
    C* const obj;
    SetterType const setter;
    GetterType const getter;
};


class Sample {
  public:
    Property<int, Sample> length{this, &Sample::set_length, &Sample::get_length};
  private:
    int _length;
    
    void set_length(int val) { _length = (val < 0) ? 0 : val; }
    int get_length() const { return _length; }
};


using namespace std;
#include <iostream>

int main() {
    Sample obj;
    obj.length = 100;
    cout << obj.length << endl;
}
