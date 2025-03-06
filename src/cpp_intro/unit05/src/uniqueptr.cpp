#include <iostream>  // uniqueptr.cpp
#include <memory>
using namespace std;
void use_ptr(int* pi) {
    cout << *pi << endl;
    // delete here?
}
int main() {
    {
        int* pi{new int{1}};
        use_ptr(pi);
        // delete here?
    }
    // no delete → memory leak!
}
