#include <iostream>  // badinput7.cpp
#include <limits>
using namespace std;
int main() {  char proceed{'y'};
  do {
    double num;  cout << "Number: ";
    if (!(cin >> num)) {
      cerr << "ungültig: Abbruch" << endl;
      cin.clear();
      // forwards by specified cnt of chars or
      //   given stop character
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n');  // ignore until eol
      continue;  }
    cout << "Proceed? [y/n] ";
    cin >> proceed;  cout << endl;
  } while (proceed == 'y');  }
