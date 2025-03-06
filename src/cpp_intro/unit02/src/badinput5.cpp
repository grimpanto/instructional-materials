#include <iostream>  // badinput5.cpp
using namespace std;
int main() {
    char proceed{'y'};
    do {
        double num;  cout << "Number: ";
        if (!(cin >> num)) {
            cerr << "ungültig: Abbruch" << endl;
            continue;
        }
        cout << "Proceed? [y/n] ";
        cin >> proceed;  cout << endl;
    } while (proceed == 'y');
}
