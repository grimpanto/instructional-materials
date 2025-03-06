
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in{"data.txt"};
    string msg;
    in >> msg;
    in.close();
    cout << "Hello " << msg << "!" << endl;
}
