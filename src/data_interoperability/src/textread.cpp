#include <iostream>
#include <fstream>
using namespace std;
int main() {
    string line;
    ifstream reader("persons.csv");
    if (!reader) {
        cout << "Error opening input file!" << endl ;
        exit(1) ;
    }
    reader >> line;  // does not consume endline char
    cout << line << endl;

    // consume the endline char
    while (getline(reader, line)) {
        cout << line << endl;
    }
    reader.close();
}
