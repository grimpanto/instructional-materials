
#include <iostream>

using namespace std;

struct Address {
    string street;
    string city;
};

struct Contact {
    string name;
    Address* address;
    Contact(string name, Address* address) :
      name{name}, address{address} {}
    Contact(const Contact& other) : name{other.name},
                                    address{new Address{*other.address}} {}
};

int main() {
    Contact c1 {"Maxi", new Address{"weg 1", "Zwergenstadt"}};
    Contact c2{c1};
    c2.address->street = "weg 42";
    cout << c1.address->street << endl;
    cout << c2.address->street << endl;
}
