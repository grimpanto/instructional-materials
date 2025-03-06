#include <iostream>  // outnums.cpp
#include <iomanip>  // setw, setfill,...
using namespace std;
int main() {
    cout << left << setw(5) << 3 << 'm' << endl;
    cout << 3 << 'm' << endl;  // reset!
    cout << internal << setw(5)<< -3<< 'm'<< endl;
    cout << right << setw(5) << -3 << 'm' << endl;
    cout<< setfill('*')<< setw(5)<< 3<< 'm'<< endl;
}
