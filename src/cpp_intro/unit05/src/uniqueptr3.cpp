#include <iostream>  // uniqueptr3.cpp
#include <memory>
using namespace std;
// void use_ptr(unique_ptr<int> upi) {  // error
void use_ptr(unique_ptr<int>& upi) {
    cout << *upi << endl;  // want to free here?
}
int main() {
    {
        unique_ptr<int> upi{new int{1}};
        use_ptr(upi);
    }  // deleted → no memory leak
}
