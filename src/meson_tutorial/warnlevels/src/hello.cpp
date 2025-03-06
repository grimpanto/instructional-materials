
#include <iostream>

using namespace std;


int main() {
    int i{};
    int* pi{&i};
    cout << (pi < 0) << endl;
}
