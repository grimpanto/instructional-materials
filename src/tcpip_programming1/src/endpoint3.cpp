#include <iostream>  // endpoint3.cpp
#include <asio.hpp>  // client-side: error_code
using namespace std;  using namespace asio;
int main() {
    string a1_str{"127.0.0.1x"};
    error_code ec;// will be set if ip is malformed
    ip::address a1{ip::make_address_v4(a1_str,ec)};
    if (ec.value() != 0) {
        cout << "Error code = " << ec.value()
             << ". Message: " << ec.message();
        return ec.value();  }
    ip::tcp::endpoint ep(a1, 1234);
    cout << ep << endl;  }
