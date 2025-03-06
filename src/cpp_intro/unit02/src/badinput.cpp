#include <iostream>  // badinput.cpp
using namespace std;
int main() {
    char proceed{'y'};

    while (proceed == 'y') {
        double num;
        cout << "Number: ";
        cin >> num;
    
        cout << "Proceed? [y/n] ";
        cin >> proceed;
        cout << endl;
    }
}
