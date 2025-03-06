#include <iostream>  // ipaddress2.cpp
#include <asio.hpp>
using namespace std;
using namespace asio;
int main() {  // class address_v4
    auto a1{ip::make_address_v4("10.0.0.1")};
    cout << ip::address_v4::any() << endl;
    cout << ip::address_v4::broadcast() << endl;
    auto a3{ip::address_v4::loopback()};
    cout << a3 << ", " << a3.is_loopback() << endl;
}
