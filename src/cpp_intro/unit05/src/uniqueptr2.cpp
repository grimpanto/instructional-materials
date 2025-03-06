#include <iostream>  // uniqueptr2.cpp
#include <memory>
using namespace std;
int main() {
    {
        unique_ptr<int> upi{new int{1}};
        cout << *upi << endl;  // like a raw ptr
    }
    // delete done!
}
