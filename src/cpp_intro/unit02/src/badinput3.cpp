#include <iostream>  // badinput3.cpp
using namespace std;
int main() {
    char proceed;  // init not necessary
    do {
        double num;
        cout << "Number: ";
        if (!(cin >> num)) {
            cerr << "ungültig: Abbruch" << endl;
            return 1;
        }
        cout << "Proceed? [y/n] ";
        cin >> proceed;  cout << endl;
    } while (proceed == 'y');  // semicolon!
}
