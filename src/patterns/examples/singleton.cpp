#include <iostream>

using namespace std;

class Singleton {
    static Singleton* singleton;
    Singleton() {}
  public:
    static Singleton* get() {
        if (!Singleton::singleton)
            Singleton::singleton = new Singleton();
        return singleton;
    }
};

Singleton* Singleton::singleton;

int main() {
    Singleton* s{Singleton::get()};
    Singleton* s2{Singleton::get()};
    cout << (s == s2) << endl;
}
