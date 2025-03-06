#include <iostream>  // array4.cpp
#include <array>
using namespace std;
int main() {
    array<int, 5> arr{1, 2, 3};
    cout << arr[10] << endl;
    try {
        cout << arr.at(10) << endl;
    } catch (const out_of_range& ex) {
        cout<<"out of range: "<<ex.what()<<endl;
    }
}
