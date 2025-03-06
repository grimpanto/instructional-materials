#include <iostream>  // badinput2.cpp
using namespace std;
int main() {
    char proceed{'y'};

    while (proceed == 'y') {
        double num;  cout << "Number: ";
        if (!(cin >> num)) {
            // cerr: unbuffered!
            cerr << "ungültig: Abbruch\n";
            return 1;
        }
        cout << "Proceed? [y/n] ";
        cin >> proceed;  cout << endl;
    }
}
