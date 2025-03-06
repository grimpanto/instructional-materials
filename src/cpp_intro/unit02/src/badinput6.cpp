#include <iostream>  // badinput6.cpp
using namespace std;
int main() {
    char proceed{'y'};
    do {
        double num;  cout << "Number: ";
        if (!(cin >> num)) {
            cerr << "ungültig: Abbruch" << endl;
            cin.clear();  // now not in error mode
            continue;
        }
        cout << "Proceed? [y/n] ";
        cin >> proceed;  cout << endl;
    } while (proceed == 'y');
}
