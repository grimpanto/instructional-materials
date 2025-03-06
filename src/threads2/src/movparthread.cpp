#include <iostream>  // movparthread.cpp
#include <thread>
using namespace std;
struct Ressource {
    int value{};
    int id{};
    Ressource(int value_) : value{value_} {}
    Ressource(Ressource&& o) {
        value = o.value;
        id = o.id + 1;
        cout<< "from "<< o.id<< " to "<< id<< endl;
        o.value = 0;
    }
    ~Ressource() { cout << "dtor: " << id <<
                   " value: " << value << endl; }
};

int main() {
    thread t1{[](Ressource&& res) { cout <<
      "t1: " << res.value << endl; },
      Ressource{42}};
    t1.join();
}
