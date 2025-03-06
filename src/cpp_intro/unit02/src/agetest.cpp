// agetest.cpp
#include <iostream>
using namespace std;

int main() {
    int age;

    cout << "How old are you? ";
    cin >> age;  // ">>" ... also for integers
    
    if (age < 18) {
        std::cout << "You are underage!" << endl;
    } else {
        std::cout << "You are full-aged!" << endl;
    }
}
