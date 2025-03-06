#include <iostream>  // ipaddress3.cpp
#include <asio.hpp>
using namespace std;
using namespace asio;
int main() {  // class address_v6
    auto a1{ip::make_address_v6("::1")};
    cout << a1 << ", " << a1.is_link_local();
    cout << " | " << ip::address_v6::any() << endl;
    auto a2{ip::address_v6::loopback()};
    cout << a2 << ", " << a2.is_loopback() << endl;
    ip::address a3{a2}; cout << a3.is_v6() << endl;
}
