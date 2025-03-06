#include <iostream>  // inline_variables.cpp
using namespace std;

#include "inline_variables.h"

int main() {
    cout << Person::next_id << endl;
    Person p1;
    cout << p1.id << endl;
    cout << Person::next_id << endl;
}
