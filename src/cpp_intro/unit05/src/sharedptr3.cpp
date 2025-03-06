#include <iostream>  // sharedptr3.cpp
#include <memory>
using namespace std;
struct Person {
    shared_ptr<Person> spouse;
    ~Person() { cout << "destructed!" << ' '; }
};
int main() {
  shared_ptr<Person> p1{make_shared<Person>()};
  shared_ptr<Person> p2{make_shared<Person>()};
  p1->spouse = p2;
  p2->spouse = p1;
  cout<<p1.use_count()<<' '<<p2.use_count()<<endl;
}
