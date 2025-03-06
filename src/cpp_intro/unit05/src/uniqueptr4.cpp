#include <iostream>  // uniqueptr4.cpp
#include <memory>
using namespace std;
void use_ptr(unique_ptr<int> upi) {
    cout << *upi << ' ';
    // deleted→no memory leak
}
int main() {
    unique_ptr<int> upi{new int{1}};
    use_ptr(move(upi));
    cout << ((upi.get()==nullptr) ? 0:*upi)<< endl;
}
