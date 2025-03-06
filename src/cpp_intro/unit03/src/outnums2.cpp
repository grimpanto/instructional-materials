#include <iostream>  // outnums2.cpp
#include <iomanip>  // setw, setfill,...
using namespace std;
int main() {
    cout << uppercase << hex << 0xcafe << endl;
    double pi = 3.1415926;
    cout << pi << ' ';
    cout << setprecision(3) << pi << ' ';
    cout << showpos << pi << endl;
    cout << showpoint << setprecision(10) << 2.78
         << endl << pi << endl;
}
