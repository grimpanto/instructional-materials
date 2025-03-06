#include <iostream>  // sharedptr2.cpp
#include <memory>
using namespace std;
struct Person {
    shared_ptr<Person> spouse;
    ~Person() { cout << "destructed!" << ' '; }
};
int main() { // guideline: use make_shared !!!
  shared_ptr<Person> p1{make_shared<Person>()};
  shared_ptr<Person> p2{make_shared<Person>()};
  cout<<p1.use_count()<<' '<<p2.use_count()<<endl;
}
