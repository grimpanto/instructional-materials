#include <iostream>  // auto.cpp
using namespace std;
auto sum(int a, int b) -> decltype(a + b) {
    return a + b;
}

int main() {
    cout<< "Summe von 3 und 5: "<< sum(3,5)<< endl;
}
