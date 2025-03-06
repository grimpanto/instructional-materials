// greetme2.cpp
#include <iostream>
using namespace std;
int main() {
    string first_name;
    string last_name;
    cout << "Your name: ";
    cin >> first_name;
    cin >> last_name;
    cout << "Pleased to meet you, " << first_name
         << " " << last_name << "!" << endl;
}
