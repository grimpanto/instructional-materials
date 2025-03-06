
#include <iostream>

using namespace std;

struct Singleton final {
  protected:
    Singleton() { /*...*/ }
  public:
    static Singleton& get() {
        static Singleton singleton;
        return singleton;
    }
    Singleton(const Singleton&)=delete;
    Singleton(Singleton&&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    Singleton& operator=(Singleton&)=delete;
};

int main() {
    Singleton& s{Singleton::get()};
    Singleton& s2{Singleton::get()};
    cout << (&s == &s2) << endl;
}
