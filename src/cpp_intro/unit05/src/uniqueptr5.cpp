#include <iostream>  // uniqueptr5.cpp
#include <memory>
using namespace std;
class Game {
    // assumptions: constructor
    //    - gets one argument (see below)
    //    - may throw exception!
};
void use_ptr(unique_ptr<Game> a,
             unique_ptr<Game> b) {};

int main() {
    // memory leak possible (until C++14)
    use_ptr(unique_ptr<Game>{new Game{1}},
            unique_ptr<Game>{new Game{2}});
}
