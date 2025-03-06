#include <iostream>  // endpoint2.cpp
#include <asio.hpp>  // client-side
using namespace std;
using namespace asio;
int main() {
    string a1_str{"127.0.0.1"};

    // throw asio::system_error if ip is malformed
    ip::address a1{ip::make_address_v4(a1_str)};
    ip::tcp::endpoint ep{a1, 1234};
    cout << ep << endl;  // -> 127.0.0.1:1234
}
