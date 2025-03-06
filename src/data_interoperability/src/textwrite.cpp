#include <iostream>  // textwrite.cpp
#include <fstream>
#include <vector>
using namespace std;
int main() {
    string line;
    ofstream writer("persons.csv");
    if (!writer) {
        cout << "Error opening output file!" << endl ;
        exit(1) ;
    }
    vector<string> lines{"3456050685;Maxi;Mustermann;Wien\n",
      "1234040584;Mini;Musterfrau;Graz\n",
      "43210306;Otto;Miesepeter;Entenhausen\n"};

    // consume the endline char
    for (const auto& line : lines) {
        if (!(writer << line)) {
            cout << "Error writing file!" << endl;
            exit(1);
        }
    }
    writer.close();
}
